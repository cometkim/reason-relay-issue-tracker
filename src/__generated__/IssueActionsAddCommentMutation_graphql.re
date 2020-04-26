/* @generated */

module Types = {
  type addCommentInput = {
    subjectId: string,
    body: string,
    clientMutationId: option(string),
  };
  type response_addComment_commentEdge_node = {id: string};
  type response_addComment_commentEdge = {
    node: option(response_addComment_commentEdge_node),
  };
  type response_addComment_subject = {
    __typename: string,
    id: string,
  };
  type response_addComment = {
    subject: option(response_addComment_subject),
    commentEdge: option(response_addComment_commentEdge),
  };

  type response = {addComment: option(response_addComment)};
  type variables = {input: addCommentInput};
};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"addComment":{"n":""},"addComment_subject":{"n":""},"addComment_commentEdge":{"n":""},"addComment_commentEdge_node":{"n":"","f":""}}} |json}
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
    {json| {"__root":{"addComment":{"n":""},"addComment_subject":{"n":""},"addComment_commentEdge":{"n":""},"addComment_commentEdge_node":{"n":"","f":""}}} |json}
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
    {json| {"__root":{"input":{"r":"AddCommentInput"}},"AddCommentInput":{"clientMutationId":{"n":""}}} |json}
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
  let make_addCommentInput =
      (~subjectId, ~body, ~clientMutationId=?, ()): addCommentInput => {
    subjectId,
    body,
    clientMutationId,
  };

  let makeVariables = (~input): variables => {input: input};

  let make_response_addComment_commentEdge_node =
      (~id): response_addComment_commentEdge_node => {
    id: id,
  };

  let make_response_addComment_commentEdge =
      (~node=?, ()): response_addComment_commentEdge => {
    node: node,
  };

  let make_response_addComment_subject =
      (~__typename, ~id): response_addComment_subject => {
    __typename,
    id,
  };

  let make_response_addComment =
      (~subject=?, ~commentEdge=?, ()): response_addComment => {
    subject,
    commentEdge,
  };

  let makeOptimisticResponse = (~addComment=?, ()): response => {
    addComment: addComment,
  };
};

type operationType = ReasonRelay.mutationNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "input",
    "type": "AddCommentInput!",
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
  "name": "__typename",
  "args": null,
  "storageKey": null
},
v3 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "id",
  "args": null,
  "storageKey": null
},
v4 = {
  "kind": "LinkedField",
  "alias": null,
  "name": "subject",
  "storageKey": null,
  "args": null,
  "concreteType": null,
  "plural": false,
  "selections": [
    (v2/*: any*/),
    (v3/*: any*/)
  ]
};
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "IssueActionsAddCommentMutation",
    "type": "Mutation",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "addComment",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "AddCommentPayload",
        "plural": false,
        "selections": [
          (v4/*: any*/),
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "commentEdge",
            "storageKey": null,
            "args": null,
            "concreteType": "IssueCommentEdge",
            "plural": false,
            "selections": [
              {
                "kind": "LinkedField",
                "alias": null,
                "name": "node",
                "storageKey": null,
                "args": null,
                "concreteType": "IssueComment",
                "plural": false,
                "selections": [
                  (v3/*: any*/),
                  {
                    "kind": "FragmentSpread",
                    "name": "IssueComment_comment",
                    "args": null
                  }
                ]
              }
            ]
          }
        ]
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "IssueActionsAddCommentMutation",
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "addComment",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "AddCommentPayload",
        "plural": false,
        "selections": [
          (v4/*: any*/),
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "commentEdge",
            "storageKey": null,
            "args": null,
            "concreteType": "IssueCommentEdge",
            "plural": false,
            "selections": [
              {
                "kind": "LinkedField",
                "alias": null,
                "name": "node",
                "storageKey": null,
                "args": null,
                "concreteType": "IssueComment",
                "plural": false,
                "selections": [
                  (v3/*: any*/),
                  {
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "author",
                    "storageKey": null,
                    "args": null,
                    "concreteType": null,
                    "plural": false,
                    "selections": [
                      (v2/*: any*/),
                      {
                        "kind": "ScalarField",
                        "alias": null,
                        "name": "login",
                        "args": null,
                        "storageKey": null
                      },
                      {
                        "kind": "ScalarField",
                        "alias": null,
                        "name": "avatarUrl",
                        "args": null,
                        "storageKey": null
                      },
                      (v3/*: any*/)
                    ]
                  },
                  {
                    "kind": "ScalarField",
                    "alias": null,
                    "name": "body",
                    "args": null,
                    "storageKey": null
                  }
                ]
              }
            ]
          }
        ]
      }
    ]
  },
  "params": {
    "operationKind": "mutation",
    "name": "IssueActionsAddCommentMutation",
    "id": null,
    "text": "mutation IssueActionsAddCommentMutation(\n  $input: AddCommentInput!\n) {\n  addComment(input: $input) {\n    subject {\n      __typename\n      id\n    }\n    commentEdge {\n      node {\n        id\n        ...IssueComment_comment\n      }\n    }\n  }\n}\n\nfragment IssueComment_comment on Comment {\n  author {\n    __typename\n    login\n    avatarUrl\n    ... on Node {\n      id\n    }\n  }\n  body\n}\n",
    "metadata": {}
  }
};
})() |json}
];
