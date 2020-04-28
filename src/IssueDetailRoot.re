module IssueDetailRootQuery = [%relay.query
  {|
    query IssueDetailRootQuery($id: ID!) {
      node(id: $id) {
        __typename
        ... on Issue {
          title
          number
          closed
          url
          ...IssueComment_comment
          ...IssueDetailComments_issue
          ...IssueActions_issue
        }
      }
    }
  |}
];

[@react.component]
let make = (~token) => {
  let data = IssueDetailRootQuery.usePreloaded(~token, ());
  switch (data.node) {
  | None => React.string("issue not found")
  | Some(`Issue(issue)) =>
    <div className="issue">
      <div className="issue-title">
        {React.string(
           "#"
           ++ string_of_int(issue.number)
           ++ " - "
           ++ issue.title
           ++ " - "
           ++ (issue.closed ? "Closed" : "Open"),
         )}
        <a
          className="issue-title-github-link"
          href={issue.url}
          title="Issue on GitHub">
          {React.string("View on GitHub")}
        </a>
      </div>
      <IssueComment comment={issue.getFragmentRefs()} />
      <IssueDetailComments issue={issue.getFragmentRefs()} />
      <IssueActions issue={issue.getFragmentRefs()} />
    </div>
  | _ => React.null
  };
};
