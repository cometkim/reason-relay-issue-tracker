[@react.component]
let make = (~route, ~children) => {
  let routeUrl = route->Route.toString;
  let route = routeUrl->Route.parse;

  let onClick =
    React.useCallback1(
      event => {
        event->ReactEvent.Mouse.preventDefault;
        routeUrl->ReasonReactRouter.push;
      },
      [|routeUrl|],
    );

  let onMouseEnter =
    React.useCallback1(
      _ => {route->Belt.Option.map(route => route->Route.preload)->ignore},
      [|route|],
    );

  <a href=routeUrl onClick onMouseEnter> children </a>;
};
