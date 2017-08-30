type union_of_string_or_regex =
  | String string
  | Regex Js.Re.t;

type string_or_regex;

external string_or_regex : union_of_string_or_regex => string_or_regex =
  "Array.prototype.shift.call" [@@bs.val];

external camelcase_keys :
  input::Js.Dict.t 'tValue =>
  options::Js.t {.. exclude : array string_or_regex}? =>
  unit =>
  Js.Dict.t 'tValue =
  "camelcase-keys" [@@bs.module];
