/* @generated */

module Types = {
  type reopenIssueInput = {
    issueId: string,
    clientMutationId: option(string),
  };
  type response_reopenIssue_issue = {closed: bool};
  type response_reopenIssue = {issue: option(response_reopenIssue_issue)};

  type response = {reopenIssue: option(response_reopenIssue)};
  type variables = {input: reopenIssueInput};
};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"reopenIssue":{"n":""},"reopenIssue_issue":{"n":""}}} |json}
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
    {json| {"__root":{"reopenIssue":{"n":""},"reopenIssue_issue":{"n":""}}} |json}
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
    {json| {"__root":{"input":{"r":"ReopenIssueInput"}},"ReopenIssueInput":{"clientMutationId":{"n":""}}} |json}
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
  let make_reopenIssueInput =
      (~issueId, ~clientMutationId=?, ()): reopenIssueInput => {
    issueId,
    clientMutationId,
  };

  let makeVariables = (~input): variables => {input: input};

  let make_response_reopenIssue_issue = (~closed): response_reopenIssue_issue => {
    closed: closed,
  };

  let make_response_reopenIssue = (~issue=?, ()): response_reopenIssue => {
    issue: issue,
  };

  let makeOptimisticResponse = (~reopenIssue=?, ()): response => {
    reopenIssue: reopenIssue,
  };
};

type operationType = ReasonRelay.mutationNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "input",
    "type": "ReopenIssueInput!",
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
    "name": "IssueActionsReopenIssueMutation",
    "type": "Mutation",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "reopenIssue",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "ReopenIssuePayload",
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
    "name": "IssueActionsReopenIssueMutation",
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "reopenIssue",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "ReopenIssuePayload",
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
    "name": "IssueActionsReopenIssueMutation",
    "id": null,
    "text": "mutation IssueActionsReopenIssueMutation(\n  $input: ReopenIssueInput!\n) {\n  reopenIssue(input: $input) {\n    issue {\n      closed\n      id\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |json}
];
