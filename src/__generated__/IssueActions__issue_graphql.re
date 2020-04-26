/* @generated */

module Types = {
  type fragment = {
    id: string,
    closed: bool,
  };
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let fragmentConverterMap = ();
  let convertFragment = v =>
    v
    ->ReasonRelay._convertObj(
        fragmentConverter,
        fragmentConverterMap,
        Js.undefined,
      );
};

type t;
type fragmentRef;
type fragmentRefSelector('a) =
  {.. "__$fragment_ref__IssueActions__issue": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| {
  "kind": "Fragment",
  "name": "IssueActions__issue",
  "type": "Issue",
  "metadata": null,
  "argumentDefinitions": [],
  "selections": [
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "id",
      "args": null,
      "storageKey": null
    },
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "closed",
      "args": null,
      "storageKey": null
    }
  ]
} |json}
];
