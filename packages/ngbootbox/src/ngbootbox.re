module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesNgbootboxIndex = {
  type ngBootboxDialog =
    Js.t {
      ..
      title : string,
      message : string,
      templateUrl : string,
      locale : string,
      callback : unit => 'any,
      onEscape : unit => any_1_or_bool,
      show : Js.boolean,
      backdrop : Js.boolean,
      closeButton : Js.boolean,
      animate : Js.boolean,
      className : string,
      size : string,
      buttons : bootboxButtonMap
    };
  type bootboxService =
    Js.t {
      ..
      alert : msg::string => Js_promise.t 'any,
      confirm : msg::string => Js_promise.t 'any,
      prompt : msg::string => Js_promise.t 'any,
      customDialog : options::ngBootboxDialog => unit,
      setDefaults : options::bootboxDefaultOptions => unit,
      hideAll : unit => unit,
      addLocale : name::string => values::bootboxLocaleValues => unit,
      removeLocale : name::string => unit,
      setLocale : name::string => unit
    };
  external _ngBootbox : bootboxService =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/ngbootbox/index"];
};
