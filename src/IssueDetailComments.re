open ReactExperimental;

module IssueFragment = [%relay.fragment
  {|
    fragment IssueDetailComments_issue on Issue
      @argumentDefinitions(
        cursor: { type: "String" }
        count: { type: "Int", defaultValue: 10 }
      )
      @refetchable(queryName: "IssueDetailCommentsQuery") {
      comments(after: $cursor, first: $count)
        @connection(key: "IssueDetailComments_comments") {
        edges {
          node {
            id
            ...IssueComment__comment
          }
        }
      }
    }
  |}
];

[@react.component]
let make = (~issue as issueRef) => {
  let issue = IssueFragment.usePagination(issueRef);
  let (startTransition, isPending) = useTransition(~timeoutMs=2000, ());
  let loadMore =
    React.useCallback3(
      _ =>
        if (!issue.isLoadingNext) {
          startTransition(_ => issue.loadNext(~count=10, ())->ignore);
        },
      (issue.isLoadingNext, issue.loadNext, startTransition),
    );
  let comments = issue.data.comments.edges;
  switch (comments) {
  | None =>
    <div className="issue-no-comments"> {React.string("No comments")} </div>
  | Some(comments) =>
    <>
      <SuspenseList revealOrder=`forwards>
        {comments
         ->Belt.Array.map(edge => {
             switch (edge) {
             | None => React.null
             | Some({node: comment}) =>
               switch (comment) {
               | None => React.null
               | Some(comment) =>
                 <Suspense fallback=React.null key={comment.id}>
                   <IssueComment comment={comment.getFragmentRefs()} />
                 </Suspense>
               }
             }
           })
         ->React.array}
      </SuspenseList>
      {issue.hasNext
         ? <button
             name="load more comments"
             className="issue-comments-load-more"
             onClick=loadMore
             disabled={isPending || issue.isLoadingNext}>
             {isPending
                ? React.string(
                    issue.isLoadingNext ? "Loading..." : "Load More",
                  )
                : React.null}
           </button>
         : React.null}
    </>
  };
};
