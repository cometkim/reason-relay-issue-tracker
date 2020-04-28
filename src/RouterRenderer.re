open ReactExperimental;

module RouteComponent = {
  [@react.component]
  let make = (~route) => {
    let data = route->Route.preload;
    let component = data.component->ReactCache.read();
    component(~token=data.token);
  };
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let route = url->Route.fromUrl;
  <Suspense fallback={React.string("Loading fallback...")}>
    {switch (route) {
     | None => React.null
     | Some(route) => <RouteComponent route />
     }}
  </Suspense>;
};
