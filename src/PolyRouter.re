module Url = {
  type t = {
    pathname: string,
    query: string,
    hash: string,
  };

  [@bs.module] [@bs.new] external make: string => t = "url-parse";

  // Taken from ReasonReactRouter
  module RouterCompat = {
    let path =
      fun
      | ""
      | "/" => []
      | raw => {
          /* remove the preceeding /, which every pathname seems to have */
          let raw = Js.String.sliceToEnd(~from=1, raw);
          /* remove the trailing /, which some pathnames might have. Ugh */
          let raw =
            switch (Js.String.get(raw, Js.String.length(raw) - 1)) {
            | "/" => Js.String.slice(~from=0, ~to_=-1, raw)
            | _ => raw
            };

          raw->Js.String2.split("/")->Belt.List.fromArray;
        };

    let hash =
      fun
      | ""
      | "#" => ""
      | raw =>
        /* remove the preceeding #, which every hash seems to have.
           Why is this even included in location.hash?? */
        raw |> Js.String.sliceToEnd(~from=1);

    let search =
      fun
      | ""
      | "?" => ""
      | raw =>
        /* remove the preceeding ?, which every search seems to have. */
        raw |> Js.String.sliceToEnd(~from=1);
  };
  let toRouterUrl: t => ReasonReactRouter.url =
    t =>
      RouterCompat.{
        path: t.pathname->path,
        search: t.query->search,
        hash: t.hash->hash,
      };
};

module type Config = {
  type route('token);
  let register:
    route('token) =>
    ReactCache.t(unit, React.component({. "token": 'token}));
  let preload: route('token) => 'token;
  let makePath: route('token) => string;
};

module Make = (Config: Config) => {
  include Config;

  let preloadCode:
    type token. route(token) => React.component({. "token": token}) =
    route => {
      route->register->ReactCache.read();
    };

  let render: type token. route(token) => React.element =
    route => {
      let component = route->preloadCode;
      let token = route->preload;
      React.createElement(component, {"token": token});
    };

  module Provider = {};

  module Renderer = {
    open ReactExperimental;
    open BsReactErrorBoundary;

    [@react.component]
    let make = () => {
      <ErrorBoundary> <Suspense> React.null </Suspense> </ErrorBoundary>;
    };
  };

  module Link = {
    [@react.component]
    let make = (~to_, ~children, ~onClick=?, ()) => {
      <a
        href=to_
        onClick={
          switch (onClick) {
          | Some(cb) => cb
          | None => (_ => ())
          }
        }>
        children
      </a>;
    };
  };
};
