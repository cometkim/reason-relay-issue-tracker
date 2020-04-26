exception Graphql_error(string);
exception TokenRequired(string);

[@bs.val]
external token: Js.Nullable.t(string) =
  "process.env.REACT_APP_GITHUB_AUTH_TOKEN";

let fetchQuery: ReasonRelay.Network.fetchFunctionPromise =
  (operation, variables, _cacheConfig) => {
    switch (token->Js.Nullable.toOption) {
    | Some(token) =>
      Fetch.(
        fetchWithInit(
          Constant.apiEndpoint,
          RequestInit.make(
            ~method_=Post,
            ~body=
              Js.Dict.fromList([
                ("query", Js.Json.string(operation.text)),
                ("variables", variables),
              ])
              |> Js.Json.object_
              |> Js.Json.stringify
              |> BodyInit.make,
            ~headers=
              HeadersInit.make({
                "content-type": "application/json",
                "accept": "application/json",
                "authorization": "bearer " ++ token,
              }),
            (),
          ),
        )
        |> Js.Promise.then_(resp =>
             if (Response.ok(resp)) {
               Response.json(resp);
             } else {
               Js.Promise.reject(
                 Graphql_error(
                   "Request failed: " ++ Response.statusText(resp),
                 ),
               );
             }
           )
      )
    | None =>
      Js.Promise.reject(
        TokenRequired(
          "This app requires a GitHub authentication token to be configured. See readme.md for setup details.",
        ),
      )
    };
  };
let network =
  ReasonRelay.Network.makePromiseBased(~fetchFunction=fetchQuery, ());
let environment =
  ReasonRelay.Environment.make(
    ~network,
    ~store=
      ReasonRelay.Store.make(~source=ReasonRelay.RecordSource.make(), ()),
    (),
  );
