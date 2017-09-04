type jWTHeader = Js.t {.. typ : string, alg : string};

type jWTObject = Js.t {.. header : jWTHeader, claim : 'any, signature : string};

external read : header::string => jWTObject = "" [@@bs.module "jwt-client"];

external write : value::jWTObject => string = "" [@@bs.module "jwt-client"];

external keep : value::jWTObject => key::'any? => storate::'any? => unit => unit =
  "" [@@bs.module "jwt-client"];

external remember : unit => unit = "" [@@bs.module "jwt-client"];

external forget : unit => unit = "" [@@bs.module "jwt-client"];

external get : unit => string = "" [@@bs.module "jwt-client"];

external validate : value::jWTObject => issuer::'any? => audience::'any? => unit => Js.boolean =
  "" [@@bs.module "jwt-client"];
