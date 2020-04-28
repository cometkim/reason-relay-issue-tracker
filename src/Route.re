type t =
  | Home
  | IssueDetail(string);

let fromUrl = (url: ReasonReactRouter.url) =>
  switch (url.path) {
  | [] => Some(Home)
  | ["issue", id] => Some(IssueDetail(id))
  | _ => None
  };

let parse = url => {
  open Webapi;
  let url = Url.make(url);
  (
    {
      path: url->Url.pathname |> String.split_on_char('/'),
      hash: url->Url.hash,
      search: url->Url.search,
    }: ReasonReactRouter.url
  )
  ->fromUrl;
};

type preloadToken =
  | Home(HomeRootQuery_graphql.preloadToken)
  | IssueDetail(IssueDetailRootQuery_graphql.preloadToken);

type data('c) = {
  component: ReactCache.t(unit, 'c),
  token: preloadToken,
};

module type PreloadableComponentType = {
  let make: (~token: preloadToken) => React.element;
};

let preload = (route: t) =>
  switch (route) {
  | Home => {
      component:
        ReactCache.make(
          () => {
            DynamicImport.(
              import("./HomeRoot.bs.js")->resolve
              <$> (
                (module Component: PreloadableComponentType) => Component.make
              )
            )
          },
          None,
        ),
      token:
        Home(
          HomeRoot.HomeRootQuery.preload(
            ~environment=RelayEnv.environment,
            ~variables={owner: "facebook", name: "relay"},
            ~fetchPolicy=StoreOrNetwork,
            (),
          ),
        ),
    }
  | IssueDetail(id) => {
      component:
        ReactCache.make(
          () => {
            DynamicImport.(
              import("./IssueDetailRoot.bs.js")->resolve
              <$> (
                (module Component: PreloadableComponentType) => Component.make
              )
            )
          },
          None,
        ),
      token:
        IssueDetail(
          IssueDetailRoot.IssueDetailRootQuery.preload(
            ~environment=RelayEnv.environment,
            ~variables={id: id},
            ~fetchPolicy=StoreOrNetwork,
            (),
          ),
        ),
    }
  };

type t';

external make: string => t' = "%identity";
external toString: t' => string = "%identity";

let home = "/"->make;
let issueDetail = id => ("/issue/" ++ id)->make;
