module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesRecaptchaIndex = {
  module Recaptcha = {
    type t =
      Js.t {
        .
        reload : (unit => unit) [@bs.meth],
        switch_type : (string => unit) [@bs.meth],
        showhelp : (unit => unit) [@bs.meth],
        get_challenge : (unit => string) [@bs.meth],
        get_response : (unit => string) [@bs.meth],
        focus_response_field : (unit => unit) [@bs.meth],
        create : (string => string => recaptchaOptions => unit) [@bs.meth],
        destroy : (unit => unit) [@bs.meth]
      };
    external make : unit => t =
      "Recaptcha"
      [@@bs.new]
      [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/recaptcha/index"];
  };
  type recaptchaOptions =
    Js.t {
      ..
      tabindex : float,
      theme : string,
      callback : 'any,
      lang : string,
      custom_theme_widget : string,
      custom_translations : customTranslations
    };
  type customTranslations =
    Js.t {
      ..
      visual_challenge : string,
      audio_challenge : string,
      refresh_btn : string,
      instructions_visual : string,
      instructions_audio : string,
      help_btn : string,
      play_again : string,
      cant_hear_this : string,
      incorrect_try_again : string,
      image_alt_text : string,
      privacy_and_terms : string
    };
};
