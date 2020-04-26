module CommentFragment = [%relay.fragment
  {|
    fragment IssueComment_comment on Comment {
      author {
        __typename
        login
        avatarUrl
      }
      body
    }
  |}
];

[@react.component]
let make = (~comment as commentRef) => {
  let comment = CommentFragment.use(commentRef);
  let author =
    comment.author
    ->Belt.Option.getWithDefault({
        __typename: "User",
        login: "ghost",
        avatarUrl: "https://avatars2.githubusercontent.com/u/10137?v=4",
      });

  <div className="issue-comment">
    <SuspenseImage
      className="issue-comment-author-image"
      title={author.login ++ "'s avatar"}
      src={author.avatarUrl}
    />
    <div className="issue-comment-author-name">
      {React.string(author.login)}
    </div>
  </div>;
};
