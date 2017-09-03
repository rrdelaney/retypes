type defaultProps =
  Js.t {
    ..
    elementID : string,
    onloadCallbackName : string,
    verifyCallbackName : string,
    expiredCallbackName : string,
    render : string,
    theme : [ | `dark | `light] [@bs.string],
    _type : string,
    size : string,
    tabindex : string
  };

type props =
  Js.t {
    ..
    className : string,
    onloadCallbackName : string,
    elementID : string,
    onloadCallback : unit => unit,
    verifyCallback : value::string => unit,
    expiredCallback : unit => unit,
    render : string,
    sitekey : string,
    theme : [ | `dark | `light] [@bs.string],
    _type : string,
    verifyCallbackName : string,
    expiredCallbackName : string,
    size : string,
    tabindex : string
  };

module Recaptcha = {
  type t =
    Js.t {
      .
      defaultProps : defaultProps,
      props : props,
      componentDidMount : (unit => unit) [@bs.meth],
      render : (unit => react_Element 'any) [@bs.meth]
    };
  external make : _::unit => t = "Recaptcha" [@@bs.new] [@@bs.module "react-recaptcha"];
};

let react_recaptcha = Recaptcha.make;
