/* @generated */

module Types = {
  type closeIssueInput = {
    issueId: string,
    clientMutationId: option(string),
  };
  type response_closeIssue_issue = {closed: bool};
  type response_closeIssue = {issue: option(response_closeIssue_issue)};

  type response = {closeIssue: option(response_closeIssue)};
  type variables = {input: closeIssueInput};
};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"closeIssue":{"n":""},"closeIssue_issue":{"n":""}}} |json}
  ];
  let wrapResponseConverterMap = ();
  let convertWrapResponse = v =>
    v
    ->ReasonRelay._convertObj(
        wrapResponseConverter,
        wrapResponseConverterMap,
        Js.null,
      );

  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"closeIssue":{"n":""},"closeIssue_issue":{"n":""}}} |json}
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
    {json| {"__root":{"input":{"r":"CloseIssueInput"}},"CloseIssueInput":{"clientMutationId":{"n":""}}} |json}
  ];
  let variablesConverterMap = ();
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

module Utils = {
  open Types;
  let make_closeIssueInput =
      (~issueId, ~clientMutationId=?, ()): closeIssueInput => {
    issueId,
    clientMutationId,
  };

  let makeVariables = (~input): variables => {input: input};

  let make_response_closeIssue_issue = (~closed): response_closeIssue_issue => {
    closed: closed,
  };

  let make_response_closeIssue = (~issue=?, ()): response_closeIssue => {
    issue: issue,
  };

  let makeOptimisticResponse = (~closeIssue=?, ()): response => {
    closeIssue: closeIssue,
  };
};

type operationType = ReasonRelay.mutationNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "input",
    "type": "CloseIssueInput!",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "Variable",
    "name": "input",
    "variableName": "input"
  }
],
v2 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "closed",
  "args": null,
  "storageKey": null
};
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "IssueActionsCloseIssueMutation",
    "type": "Mutation",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "closeIssue",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "CloseIssuePayload",
        "plural": false,
        "selections": [
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "issue",
            "storageKey": null,
            "args": null,
            "concreteType": "Issue",
            "plural": false,
            "selections": [
              (v2/*: any*/)
            ]
          }
        ]
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "IssueActionsCloseIssueMutation",
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "closeIssue",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "CloseIssuePayload",
        "plural": false,
        "selections": [
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "issue",
            "storageKey": null,
            "args": null,
            "concreteType": "Issue",
            "plural": false,
            "selections": [
              (v2/*: any*/),
              {
                "kind": "ScalarField",
                "alias": null,
                "name": "id",
                "args": null,
                "storageKey": null
              }
            ]
          }
        ]
      }
    ]
  },
  "params": {
    "operationKind": "mutation",
    "name": "IssueActionsCloseIssueMutation",
    "id": null,
    "text": "mutation IssueActionsCloseIssueMutation(\n  $input: CloseIssueInput!\n) {\n  closeIssue(input: $input) {\n    issue {\n      closed\n      id\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |json}
];
