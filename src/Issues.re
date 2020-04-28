module IssuesFragment = [%relay.fragment
  {|
    fragment Issues_issues on Repository
      @argumentDefinitions(
        cursor: { type: "String" }
        count: { type: "Int", defaultValue: 10 }
        states: { type: "[IssueState!]", defaultValue: ["OPEN"] }
      )
      @refetchable(queryName: "IssuesPaginationQuery") {
      issues(after: $cursor, first: $count, states: $states)
        @connection(key: "Issues_issues") {
        edges {
          node {
            id
            # Compose the data dependencies of child components
            # by spreading their fragments:
            ...IssuesListItem_issue
          }
        }
      }
    }
  |}
];

[@react.component]
let make = (~issues as issuesRef) => {
  let issues = IssuesFragment.usePagination(issuesRef);

  let loadMore =
    React.useCallback2(
      _ =>
        if (!issues.isLoadingNext) {
          issues.loadNext(~count=10, ())->ignore;
        },
      (issues.isLoadingNext, issues.loadNext),
    );

  <div className="issues">
    {switch (issues.data.issues.edges) {
     | None => React.null
     | Some(edges) =>
       edges
       ->Belt.Array.map(edge => {
           switch (edge) {
           | None => React.null
           | Some({node: issue}) =>
             switch (issue) {
             | None => React.null
             | Some(issue) =>
               <div className="issues-issue" key={issue.id}>
                 <IssuesListItem issue={issue.getFragmentRefs()} />
               </div>
             }
           }
         })
       ->React.array
     }}
    <button
      name="load more issues" className="issues-load-more" onClick=loadMore>
      {React.string("Load More")}
    </button>
  </div>;
};
