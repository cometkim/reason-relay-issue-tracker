open ReactExperimental;

module RootQuery = [%relay.query
  {|
    query RootQuery($owner: String!, $name: String!) {
      repository(owner: $owner, name: $name) {
        owner {
          __typename
          login
        }
        name
      }
    }
  |}
];

let make = (~token, children) => {
  let data = RootQuery.usePreloaded(~token, ());
  switch (data.repository) {
  | None => React.string("No repository found")
  | Some(repository) =>
    <div className="root">
      <header className="header">
        {React.string(
           repository.owner.login ++ "/" ++ repository.name ++ ": Issues",
         )}
      </header>
      <section className="content">
        <Suspense fallback={React.string("Loading ...")}> children </Suspense>
      </section>
    </div>
  };
};
