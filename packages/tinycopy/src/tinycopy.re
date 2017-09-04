module TinyCopy = {
  type t =
    Js.t {
      .
      on : (success => data::string => unit => this) [@bs.meth],
      on : (error => err::error => unit => this) [@bs.meth],
      on :
        (string => e::[ | `String string | `Error error] [@bs.unwrap] => unit => this) [@bs.meth],
      exec : (string => err::error? => data::string? => unit => unit => unit) [@bs.meth]
    };
  external make :
    element =>
    [ | `String string | `Element element | `NodeListOf (nodeListOf element)] [@bs.unwrap] =>
    t =
    "TinyCopy" [@@bs.new] [@@bs.module "tinycopy"];
};
