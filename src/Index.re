[@raw {| require('./index.css') |}]
ReactExperimental.renderConcurrentRootAtElementWithId(
  <ReasonRelay.Context.Provider environment=RelayEnv.environment>
    <BsReactErrorBoundary.ErrorBoundary>
      <App />
    </BsReactErrorBoundary.ErrorBoundary>
  </ReasonRelay.Context.Provider>,
  "root",
);
