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
  <Router.Link to_={"/issue/" ++ issue.id}>
    {React.string(issue.title)}
  </Router.Link>;
};
