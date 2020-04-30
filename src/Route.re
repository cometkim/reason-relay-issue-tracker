module type RootModule = (module type of Root);

let routes =
  Router.Route.make(
    ~component=
      ReactCache.make(
        ~loader=
          () => {
            DynamicImport.
              (import("./Root.bs")->resolve)
              /* <$> ((module Component: RootModule) => Component.make) */
          },
        (),
      ),
    ~matchUrl=_ => Some(),
    ~prepare=
      () => {
        RootQuery_graphql.preload(
          ~environment=RelayEnv.environment,
          ~variables={owner: "facebook", name: "relay"},
          ~fetchPolicy=StoreOrNetwork,
          (),
        )
      },
    ~render=(token, children) => <Root token> children </Root>,
    ~subRoutes=[|
      Router.Route.make(
        ~component=
          ReactCache.make(
            ~loader=() => {DynamicImport.(import("./HomeRoot.bs")->resolve)},
            (),
          ),
        ~matchUrl=
          url => {
            switch (url.path) {
            | [] => Some()
            | _ => None
            }
          },
        ~prepare=
          () => {
            HomeRootQuery_graphql.preload(
              ~environment=RelayEnv.environment,
              ~variables={owner: "facebook", name: "relay"},
              ~fetchPolicy=StoreOrNetwork,
              (),
            )
          },
        ~render=(token, _) => <HomeRoot token />,
        (),
      ),
      Router.Route.make(
        ~component=
          ReactCache.make(
            ~loader=
              () => {DynamicImport.(import("./IssueDetailRoot.bs")->resolve)},
            (),
          ),
        ~matchUrl=
          url => {
            switch (url.path) {
            | ["issue", id] => Some(id)
            | _ => None
            }
          },
        ~prepare=
          id => {
            IssueDetailRootQuery_graphql.preload(
              ~environment=RelayEnv.environment,
              ~variables={id: id},
              ~fetchPolicy=StoreOrNetwork,
              (),
            )
          },
        ~render=(token, _) => <IssueDetailRoot token />,
        (),
      ),
    |],
    (),
  );
