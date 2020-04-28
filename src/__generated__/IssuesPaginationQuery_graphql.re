/* @generated */

type enum_IssueState = [ | `CLOSED | `OPEN | `FutureAddedValue(string)];

let unwrap_enum_IssueState: string => enum_IssueState =
  fun
  | "CLOSED" => `CLOSED
  | "OPEN" => `OPEN
  | v => `FutureAddedValue(v);

let wrap_enum_IssueState: enum_IssueState => string =
  fun
  | `CLOSED => "CLOSED"
  | `OPEN => "OPEN"
  | `FutureAddedValue(v) => v;

module Types = {
  type response_node = {
    getFragmentRefs:
      unit => {. "__$fragment_ref__Issues_issues": Issues_issues_graphql.t},
  };

  type response = {node: option(response_node)};
  type refetchVariables = {
    cursor: option(string),
    count: option(int),
    states: option(array([ | `CLOSED | `OPEN | `FutureAddedValue(string)])),
    id: option(string),
  };
  let makeRefetchVariables =
      (~cursor=?, ~count=?, ~states=?, ~id=?, ()): refetchVariables => {
    cursor,
    count,
    states,
    id,
  };
  type variables = {
    cursor: option(string),
    count: option(int),
    states: option(array([ | `CLOSED | `OPEN | `FutureAddedValue(string)])),
    id: string,
  };
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"node":{"n":"","f":""}}} |json}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"cursor":{"n":""},"count":{"n":""},"states":{"n":"","e":"enum_IssueState"}}} |json}
  ];
  let variablesConverterMap = {"enum_IssueState": wrap_enum_IssueState};
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

type preloadToken;

module Utils = {
  open Types;
  let makeVariables = (~cursor=?, ~count=?, ~states=?, ~id, ()): variables => {
    cursor,
    count,
    states,
    id,
  };
};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "cursor",
    "type": "String",
    "defaultValue": null
  },
  {
    "kind": "LocalArgument",
    "name": "count",
    "type": "Int",
    "defaultValue": 10
  },
  {
    "kind": "LocalArgument",
    "name": "states",
    "type": "[IssueState!]",
    "defaultValue": [
      "OPEN"
    ]
  },
  {
    "kind": "LocalArgument",
    "name": "id",
    "type": "ID!",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "Variable",
    "name": "id",
    "variableName": "id"
  }
],
v2 = {
  "kind": "Variable",
  "name": "states",
  "variableName": "states"
},
v3 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "__typename",
  "args": null,
  "storageKey": null
},
v4 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "id",
  "args": null,
  "storageKey": null
},
v5 = [
  {
    "kind": "Variable",
    "name": "after",
    "variableName": "cursor"
  },
  {
    "kind": "Variable",
    "name": "first",
    "variableName": "count"
  },
  (v2/*: any*/)
];
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "IssuesPaginationQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "node",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": null,
        "plural": false,
        "selections": [
          {
            "kind": "FragmentSpread",
            "name": "Issues_issues",
            "args": [
              {
                "kind": "Variable",
                "name": "count",
                "variableName": "count"
              },
              {
                "kind": "Variable",
                "name": "cursor",
                "variableName": "cursor"
              },
              (v2/*: any*/)
            ]
          }
        ]
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "IssuesPaginationQuery",
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "node",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": null,
        "plural": false,
        "selections": [
          (v3/*: any*/),
          (v4/*: any*/),
          {
            "kind": "InlineFragment",
            "type": "Repository",
            "selections": [
              {
                "kind": "LinkedField",
                "alias": null,
                "name": "issues",
                "storageKey": null,
                "args": (v5/*: any*/),
                "concreteType": "IssueConnection",
                "plural": false,
                "selections": [
                  {
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "edges",
                    "storageKey": null,
                    "args": null,
                    "concreteType": "IssueEdge",
                    "plural": true,
                    "selections": [
                      {
                        "kind": "LinkedField",
                        "alias": null,
                        "name": "node",
                        "storageKey": null,
                        "args": null,
                        "concreteType": "Issue",
                        "plural": false,
                        "selections": [
                          (v4/*: any*/),
                          {
                            "kind": "ScalarField",
                            "alias": null,
                            "name": "title",
                            "args": null,
                            "storageKey": null
                          },
                          (v3/*: any*/)
                        ]
                      },
                      {
                        "kind": "ScalarField",
                        "alias": null,
                        "name": "cursor",
                        "args": null,
                        "storageKey": null
                      }
                    ]
                  },
                  {
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "pageInfo",
                    "storageKey": null,
                    "args": null,
                    "concreteType": "PageInfo",
                    "plural": false,
                    "selections": [
                      {
                        "kind": "ScalarField",
                        "alias": null,
                        "name": "endCursor",
                        "args": null,
                        "storageKey": null
                      },
                      {
                        "kind": "ScalarField",
                        "alias": null,
                        "name": "hasNextPage",
                        "args": null,
                        "storageKey": null
                      }
                    ]
                  }
                ]
              },
              {
                "kind": "LinkedHandle",
                "alias": null,
                "name": "issues",
                "args": (v5/*: any*/),
                "handle": "connection",
                "key": "Issues_issues",
                "filters": [
                  "states"
                ]
              }
            ]
          }
        ]
      }
    ]
  },
  "params": {
    "operationKind": "query",
    "name": "IssuesPaginationQuery",
    "id": null,
    "text": "query IssuesPaginationQuery(\n  $cursor: String\n  $count: Int = 10\n  $states: [IssueState!] = [OPEN]\n  $id: ID!\n) {\n  node(id: $id) {\n    __typename\n    ...Issues_issues_a4QoT\n    id\n  }\n}\n\nfragment IssuesListItem_issue on Issue {\n  id\n  title\n}\n\nfragment Issues_issues_a4QoT on Repository {\n  issues(after: $cursor, first: $count, states: $states) {\n    edges {\n      node {\n        id\n        ...IssuesListItem_issue\n        __typename\n      }\n      cursor\n    }\n    pageInfo {\n      endCursor\n      hasNextPage\n    }\n  }\n  id\n}\n",
    "metadata": {
      "derivedFrom": "Issues_issues",
      "isRefetchableQuery": true
    }
  }
};
})() |json}
];
