type matches = Js.t {.. start : float, _end : float, pre : string, body : string, post : string};

external balanced_match_apply :
  a::[ | `String string | `Regex Js.Re.t] [@bs.unwrap] =>
  b::[ | `String string | `Regex Js.Re.t] [@bs.unwrap] =>
  str::string =>
  matches_or_unit =
  "" [@@bs.module "balanced_match"];

external balanced_match :
  Js.t {.. range : a::string => b::string => str::string => array_number_or_unit} =
  "balanced-match" [@@bs.module];
