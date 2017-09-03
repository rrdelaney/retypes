external type_is_apply : req::'any => types::array string? => unit => string_or_bool_or_null =
  "" [@@bs.module "type_is"];

external type_is :
  Js.t {
    ..
    is : value::string => types::array string => string_or_bool,
    hasBody : request::'any => Js.boolean,
    normalize : type::string => bool_or_string,
    match : expected::string => actual::string => Js.boolean
  } =
  "type-is" [@@bs.module];
