type reactCSSTransitionGroupNames =
  Js.t {
    ..
    enter : string,
    enterActive : string,
    leave : string,
    leaveActive : string,
    appear : string,
    appearActive : string
  };

type union_of_string_or_reactCSSTransitionGroupNames =
  | String string
  | ReactCSSTransitionGroupNames reactCSSTransitionGroupNames;

type string_or_reactCSSTransitionGroupNames;

external string_or_reactCSSTransitionGroupNames :
  union_of_string_or_reactCSSTransitionGroupNames => string_or_reactCSSTransitionGroupNames =
  "Array.prototype.shift.call" [@@bs.val];

type props =
  Js.t {
    ..
    transitionName : string_or_reactCSSTransitionGroupNames,
    transitionAppear : Js.boolean,
    transitionEnter : Js.boolean,
    transitionLeave : Js.boolean,
    transitionAppearTimeout : float,
    transitionEnterTimeout : float,
    transitionLeaveTimeout : float
  };

type defaultProps =
  Js.t {
    ..
    transitionAppear : Js.boolean, transitionEnter : Js.boolean, transitionLeave : Js.boolean
  };

module ReactCSSTransitionGroup = {
  type t = Js.t {. defaultProps : defaultProps};
  external make : _::unit => t =
    "ReactCSSTransitionGroup" [@@bs.new] [@@bs.module "react-addons-css-transition-group"];
};

let react_addons_css_transition_group = ReactCSSTransitionGroup.make;
