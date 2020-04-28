[@raw {| require('./index.css') |}]
ReactExperimental.renderConcurrentRootAtElementWithId(
  <ReasonRelay.Context.Provider environment=RelayEnv.environment>
    <BsReactErrorBoundary.ErrorBoundary>
      <RouterRenderer />
    </BsReactErrorBoundary.ErrorBoundary>
  </ReasonRelay.Context.Provider>,
  "root",
);
