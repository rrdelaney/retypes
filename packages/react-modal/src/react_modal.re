type defaultProps =
  Js.t {
    ..
    isOpen : Js.boolean,
    ariaHideApp : Js.boolean,
    closeTimeoutMS : float,
    shouldCloseOnOverlayClick : Js.boolean
  };

type props =
  Js.t {
    ..
    isOpen : Js.boolean,
    style : Js.t {.. content : 'any, overlay : 'any},
    appElement : hTMLElement,
    ariaHideApp : Js.boolean,
    closeTimeoutMS : float,
    onAfterOpen : unit => 'any,
    onRequestClose : event::event => 'any,
    shouldCloseOnOverlayClick : Js.boolean
  };

module Modal = {
  type t =
    Js.t {
      .
      setAppElement :
        ([ | `HTMLElement hTMLElement | `String string] [@bs.unwrap] => unit) [@bs.meth],
      defaultProps : defaultProps,
      props : props
    };
  external make : _::unit => t = "Modal" [@@bs.new] [@@bs.module "react-modal"];
};

let react_modal = Modal.make;
