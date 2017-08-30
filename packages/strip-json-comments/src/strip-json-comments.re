external strip_json_comments :
  input::string => options::Js.t {.. whitespace : Js.boolean}? => unit => string =
  "strip-json-comments" [@@bs.module];
