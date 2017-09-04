module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesDoccookiesIndex = {
  type docCookies =
    Js.t {
      ..
      setItem :
        sKey::string =>
        sValue::string =>
        vEnd::float? =>
        sPath::string? =>
        sDomain::string? =>
        bSecure::Js.boolean? =>
        unit =>
        Js.boolean,
      setItem :
        sKey::string =>
        sValue::string =>
        vEnd::string? =>
        sPath::string? =>
        sDomain::string? =>
        bSecure::Js.boolean? =>
        unit =>
        Js.boolean,
      setItem :
        sKey::string =>
        sValue::string =>
        vEnd::Js.Date.t? =>
        sPath::string? =>
        sDomain::string? =>
        bSecure::Js.boolean? =>
        unit =>
        Js.boolean,
      getItem : sKey::string => string,
      removeItem : sKey::string => sPath::string? => unit => Js.boolean,
      hasItem : sKey::string => Js.boolean,
      keys : unit => array string
    };
  external docCookies : docCookies =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/doccookies/index"];
};
