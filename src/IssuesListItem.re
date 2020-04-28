module IssueFragment = [%relay.fragment
  {|
    fragment IssuesListItem_issue on Issue {
      id
      title
    }
  |}
];

[@react.component]
let make = (~issue as issueRef) => {
  let issue = IssueFragment.use(issueRef);
  <Link route={Route.issueDetail(issue.id)}>
    {React.string(issue.title)}
  </Link>;
};
