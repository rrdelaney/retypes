type webFontConfig =
  Js.t {
    ..
    loading : unit => 'any,
    active : unit => 'any,
    inactive : unit => 'any,
    fontloading : familyName::string => fvd::string => 'any,
    fontactive : familyName::string => fvd::string => 'any,
    fontinactive : familyName::string => fvd::string => 'any,
    classes : Js.boolean,
    events : Js.boolean,
    timeouts : float,
    custom :
      Js.t {.. families : array string, urls : array string, testStrings : Js.Dict.t string},
    fontdeck : Js.t {.. id : string},
    monotype : Js.t {.. projectId : string, version : float},
    google : Js.t {.. families : array string, text : string},
    typekit : Js.t {.. id : string}
  };

module WebFont = {
  type t = Js.t {. load : (webFontConfig => unit) [@bs.meth]};
  external make : _::unit => t = "WebFont" [@@bs.new] [@@bs.module "webfontloader"];
};

external webfontloader : WebFont.t = "webfontloader" [@@bs.module];
