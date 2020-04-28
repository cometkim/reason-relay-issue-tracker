module HomeRootQuery = [%relay.query
  {|
    query HomeRootQuery($owner: String!, $name: String!) {
      repository(owner: $owner, name: $name) {
        # Compose the data dependencies of child components
        # by spreading their fragments:
        ...Issues_issues
      }
    }
  |}
];

[@react.component]
let make = (~token) => {
  let data = HomeRootQuery.usePreloaded(~token, ());
  switch (data.repository) {
  | None => React.null
  | Some(repository) => <Issues issues={repository.getFragmentRefs()} />
  };
};
