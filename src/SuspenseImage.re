module Image = {
  type t;
  type onload = unit => unit;
  type onerror = exn => unit;

  [@bs.new] external make: unit => t = "Image";

  [@bs.set] external setSource: (t, string) => unit = "src";
  [@bs.set] external setOnLoad: (t, onload) => unit = "onload";
  [@bs.set] external setOnError: (t, onerror) => unit = "onerror";
};

let imageResource =
  ReactCache.make(
    ~loader=
      src => {
        Js.Promise.make((~resolve, ~reject) => {
          let image = Image.make();
          image->Image.setOnLoad(_ => resolve(. src));
          image->Image.setOnError(exn => reject(. exn));
          image->Image.setSource(src);
        })
      },
    (),
  );

[@react.component]
let make = (~src, ~className, ~title) => {
  imageResource->ReactCache.read(src)->ignore;
  <img src className title />;
};
