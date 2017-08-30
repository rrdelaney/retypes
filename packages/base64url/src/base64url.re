external base64url_apply :
  value::[ | `String string | `Buffer buffer] [@bs.unwrap] =>
  encoding::buffer_Encoding? =>
  unit =>
  string =
  "" [@@bs.module "base64url"];

external base64url :
  Js.t {
    ..
    encode :
      value::[ | `String string | `Buffer buffer] [@bs.unwrap] =>
      encoding::buffer_Encoding? =>
      unit =>
      string,
    decode : value::string => encoding::buffer_Encoding? => unit => string,
    toBuffer : value::string => buffer,
    fromBase64 : value::string => string,
    toBase64 : value::string => string
  } =
  "base64url" [@@bs.module];
