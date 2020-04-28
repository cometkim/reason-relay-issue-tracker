type t =
  | Home
  | IssueDetail(string);

let fromUrl: ReasonReactRouter.url => option(t);

let parse: string => option(t);

type preloadToken =
  | Home(HomeRootQuery_graphql.preloadToken)
  | IssueDetail(IssueDetailRootQuery_graphql.preloadToken);

type data('c) = {
  component: ReactCache.t(unit, 'c),
  token: preloadToken,
};

let preload: t => data((~token: preloadToken) => React.element);

type t';

external toString: t' => string = "%identity";

let home: t';
let issueDetail: string => t';