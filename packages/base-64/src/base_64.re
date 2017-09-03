external base_64 :
  Js.t {.. version : string, encode : input::string => string, decode : input::string => string} =
  "base-64" [@@bs.module];
