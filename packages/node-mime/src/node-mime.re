type mimeMap = Js.Dict.t (array string);

external mime :
  Js.t {
    ..
    define : map::mimeMap => unit,
    load : file::string => unit,
    lookup : path::string => fallback::string? => unit => string,
    extension : mimeType::string => string,
    default_type : string,
    charsets : Js.t {.. lookup : mimeType::string => fallback::string => string}
  } =
  "mime" [@@bs.module];
