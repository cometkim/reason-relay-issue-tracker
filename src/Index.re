[%raw {| require('./index.css') |}];

let (router, _) = Router.make([|Route.routes|]);
ReactExperimental.renderConcurrentRootAtElementWithId(
  <ReasonRelay.Context.Provider environment=RelayEnv.environment>
    <Router.Provider value={Some(router)}>
      <Router.RouteRenderer
        renderPending={() => {
          <div className="RouteRenderer-pending">
            {React.string("Loading pending...")}
          </div>
        }}
      />
    </Router.Provider>
  </ReasonRelay.Context.Provider>,
  "root",
);
