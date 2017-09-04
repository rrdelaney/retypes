type union_of_lAErrorAuthenticationFailed_or_lAErrorUserCancel_or_lAErrorUserFallback_or_lAErrorSystemCancel_or_lAErrorPasscodeNotSet_or_lAErrorTouchIDNotAvailable_or_lAErrorTouchIDNotEnrolled_or_lAErrorTouchIDNotEnrolled_or_rCTTouchIDUnknownError_or_rCTTouchIDNotSupported =
  | LAErrorAuthenticationFailed lAErrorAuthenticationFailed
  | LAErrorUserCancel lAErrorUserCancel
  | LAErrorUserFallback lAErrorUserFallback
  | LAErrorSystemCancel lAErrorSystemCancel
  | LAErrorPasscodeNotSet lAErrorPasscodeNotSet
  | LAErrorTouchIDNotAvailable lAErrorTouchIDNotAvailable
  | LAErrorTouchIDNotEnrolled lAErrorTouchIDNotEnrolled
  | LAErrorTouchIDNotEnrolled lAErrorTouchIDNotEnrolled
  | RCTTouchIDUnknownError rCTTouchIDUnknownError
  | RCTTouchIDNotSupported rCTTouchIDNotSupported;

type lAErrorAuthenticationFailed_or_lAErrorUserCancel_or_lAErrorUserFallback_or_lAErrorSystemCancel_or_lAErrorPasscodeNotSet_or_lAErrorTouchIDNotAvailable_or_lAErrorTouchIDNotEnrolled_or_lAErrorTouchIDNotEnrolled_or_rCTTouchIDUnknownError_or_rCTTouchIDNotSupported;

external lAErrorAuthenticationFailed_or_lAErrorUserCancel_or_lAErrorUserFallback_or_lAErrorSystemCancel_or_lAErrorPasscodeNotSet_or_lAErrorTouchIDNotAvailable_or_lAErrorTouchIDNotEnrolled_or_lAErrorTouchIDNotEnrolled_or_rCTTouchIDUnknownError_or_rCTTouchIDNotSupported :
  union_of_lAErrorAuthenticationFailed_or_lAErrorUserCancel_or_lAErrorUserFallback_or_lAErrorSystemCancel_or_lAErrorPasscodeNotSet_or_lAErrorTouchIDNotAvailable_or_lAErrorTouchIDNotEnrolled_or_lAErrorTouchIDNotEnrolled_or_rCTTouchIDUnknownError_or_rCTTouchIDNotSupported =>
  lAErrorAuthenticationFailed_or_lAErrorUserCancel_or_lAErrorUserFallback_or_lAErrorSystemCancel_or_lAErrorPasscodeNotSet_or_lAErrorTouchIDNotAvailable_or_lAErrorTouchIDNotEnrolled_or_lAErrorTouchIDNotEnrolled_or_rCTTouchIDUnknownError_or_rCTTouchIDNotSupported =
  "Array.prototype.shift.call" [@@bs.val];

module TouchIDError = {
  type t =
    Js.t {
      .
      name : lAErrorAuthenticationFailed_or_lAErrorUserCancel_or_lAErrorUserFallback_or_lAErrorSystemCancel_or_lAErrorPasscodeNotSet_or_lAErrorTouchIDNotAvailable_or_lAErrorTouchIDNotEnrolled_or_lAErrorTouchIDNotEnrolled_or_rCTTouchIDUnknownError_or_rCTTouchIDNotSupported,
      message : string,
      details : 'any
    };
  external make : _::unit => t = "TouchIDError" [@@bs.new] [@@bs.module "react-native-touch-id"];
};

external isSupported : unit => Js_promise.t bool_or_touchIDError =
  "" [@@bs.module "react-native-touch-id"];

external authenticate : reason::string => Js_promise.t bool_or_touchIDError =
  "" [@@bs.module "react-native-touch-id"];
