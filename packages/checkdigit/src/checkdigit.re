type checkdigit =
  Js.t {
    ..
    isValid : digits::string => Js.boolean,
    create : digits::string => string,
    apply : digits::string => string
  };

external checkdigit : Js.t {.. mod10 : checkdigit, mod11 : checkdigit} =
  "checkdigit" [@@bs.module];
