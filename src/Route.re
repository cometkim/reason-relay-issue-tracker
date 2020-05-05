module type RootModule = (module type of Root);
module type HomeRootModule = (module type of HomeRoot);
module type IssueDetailRootModule = (module type of IssueDetailRoot);

module IssueTrackerRouter =
  PolyRouter.Make({
    type route('token) =
      | HomeRoute: route(HomeRootQuery_graphql.preloadToken)
      | IssueDetail(string)
        : route(IssueDetailRootQuery_graphql.preloadToken);

    let makePath: type token. route(token) => string =
      route =>
        switch (route) {
        | HomeRoute => "/"
        | IssueDetail(id) => "/issue/" ++ id
        };

    let homeRootCode =
      ReactCache.make(
        ~loader=
          () => {
            DynamicImport.(
              import("./HomeRoot.bs")->resolve
              <$> ((module Component: HomeRootModule) => Component.make)
            )
          },
        (),
      );

    let issueDetailRootCode =
      ReactCache.make(
        ~loader=
          () => {
            DynamicImport.(
              import("./IssueDetailRoot.bs")->resolve
              <$> (
                (module Component: IssueDetailRootModule) => Component.make
              )
            )
          },
        (),
      );

    let register:
      type token.
        route(token) =>
        ReactCache.t(unit, React.component({. "token": token})) =
      route =>
        switch (route) {
        | HomeRoute => homeRootCode
        | IssueDetail(_) => issueDetailRootCode
        };

    let preload: type token. route(token) => token =
      route => {
        switch (route) {
        | HomeRoute =>
          HomeRootQuery_graphql.preload(
            ~environment=RelayEnv.environment,
            ~variables={owner: "facebook", name: "relay"},
            ~fetchPolicy=StoreAndNetwork,
            (),
          )
        | IssueDetail(id) =>
          IssueDetailRootQuery_graphql.preload(
            ~environment=RelayEnv.environment,
            ~variables={id: id},
            ~fetchPolicy=StoreAndNetwork,
            (),
          )
        };
      };
  });

let routes =
  Router.Route.make(
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
              ~fetchPolicy=StoreAndNetwork,
              (),
            )
          },
        ~render=(token, _) => <HomeRoot token />,
        (),
      ),
      Router.Route.make(
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
