module CommentFragment = [%relay.fragment
  {|
    fragment IssueComment__comment on Comment {
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

  <div className="issue-comment">
    {switch (comment.author) {
     | Some(author) =>
       <>
         <SuspenseImage
           className="issue-comment-author-image"
           title={author.login ++ "'s avatar"}
           alt={author.login ++ "'s avatar"}
           src={author.avatarUrl}
         />
         <div className="issue-comment-author-name">
           {React.string(author.login)}
         </div>
       </>
     | None =>
       <>
         <SuspenseImage
           className="issue-comment-author-image"
           title="A deleted user"
           alt="A deleted user"
           src="https://avatars2.githubusercontent.com/u/10137"
         />
         <div className="issue-comment-author-name">
           {React.string("ghost")}
         </div>
       </>
     }}
    <div className="issue-comment-body" />
  </div>;
};
