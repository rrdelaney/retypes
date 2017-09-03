external safe_regex :
  re::[ | `Regex Js.Re.t | `String string] [@bs.unwrap] =>
  options::Js.t {.. limit : float}? =>
  unit =>
  Js.boolean =
  "safe-regex" [@@bs.module];
