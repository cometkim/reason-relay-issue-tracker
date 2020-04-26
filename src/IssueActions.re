open ReasonRelay;

module IssueFragment = [%relay.fragment
  {|
    fragment IssueActions__issue on Issue {
      id
      closed
    }
  |}
];

module AddCommentMutation = [%relay.mutation
  {|
    mutation IssueActionsAddCommentMutation($input: AddCommentInput!) {
      addComment(input: $input) {
        subject {
          __typename
          id
        }
        commentEdge {
          node {
            id
            ...IssueComment__comment
          }
        }
      }
    }
  |}
];

module CloseIssueMutation = [%relay.mutation
  {|
    mutation IssueActionsCloseIssueMutation($input: CloseIssueInput!) {
      closeIssue(input: $input) {
        issue {
          closed
        }
      }
    }
  |}
];

module ReopenIssueMutation = [%relay.mutation
  {|
    mutation IssueActionsReopenIssueMutation($input: ReopenIssueInput!) {
      reopenIssue(input: $input) {
        issue {
          closed
        }
      }
    }
  |}
];

[@react.component]
let make = (~issue as issueRef) => {
  let (commentText, setCommentText) = React.useState(_ => "");

  let (addComment, isCommentPending) = AddCommentMutation.use();
  let (closeIssue, isClosePending) = CloseIssueMutation.use();
  let (reopenIssue, isReopenPending) = ReopenIssueMutation.use();
  let isPending = isCommentPending || isClosePending || isReopenPending;

  let issue = IssueFragment.use(issueRef);
  let issueId = issue.id;

  let onChange =
    React.useCallback0(event => {
      let value = event->ReactEvent.Form.currentTarget##value;
      setCommentText(_ => value);
    });

  let onSubmit =
    React.useCallback3(
      event => {
        event->ReactEvent.Form.preventDefault;
        addComment(
          ~variables={
            input: {
              body: commentText,
              subjectId: issueId,
              clientMutationId: None,
            },
          },
          ~updater=
            (store, _) =>
              store
              ->RecordSourceSelectorProxy.get(~dataId=makeDataId(issueId))
              ->Belt.Option.map(issue =>
                  ConnectionHandler.getConnection(
                    ~record=issue,
                    ~key="IssueDetailComments_comments",
                    (),
                  )
                  ->Belt.Option.map(comments =>
                      store
                      ->RecordSourceSelectorProxy.getRootField(
                          ~fieldName="addComment",
                        )
                      ->Belt.Option.map(record =>
                          record
                          ->RecordProxy.getLinkedRecord(
                              ~name="commentEdge",
                              (),
                            )
                          ->Belt.Option.map(record =>
                              ConnectionHandler.insertEdgeAfter(
                                ~connection=comments,
                                ~newEdge=record,
                                (),
                              )
                            )
                        )
                    )
                )
              ->ignore,
          (),
        )
        ->ignore;
      },
      (commentText, issueId, addComment),
    );
  ();

  let onToggleOpen =
    React.useCallback3(
      event => {
        event->ReactEvent.Mouse.preventDefault;
        issue.closed
          ? reopenIssue(
              ~variables={
                input: {
                  issueId,
                  clientMutationId: None,
                },
              },
              (),
            )
            ->ignore
          : closeIssue(
              ~variables={
                input: {
                  issueId,
                  clientMutationId: None,
                },
              },
              (),
            )
            ->ignore;
      },
      (issue, reopenIssue, closeIssue),
    );

  <form className="issue-actions" onSubmit>
    <textarea
      className="issue-actions-text"
      onChange
      value=commentText
      placeholder="Leave a comment"
    />
    <button
      className="issue-actions-button"
      type_="submit"
      disabled={isPending || commentText->String.trim == ""}>
      {React.string("Comment")}
    </button>
    <button
      className="issue-actions-button"
      type_="button"
      onClick=onToggleOpen
      disabled=isPending>
      {React.string(issue.closed ? "Reopen" : "Close")}
    </button>
  </form>;
};
