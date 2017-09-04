module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesJssIndex = {
  type properties = Js.Dict.t string;
  type selectors = Js.Dict.t properties;
  type jSS =
    Js.t {
      ..
      get : unit => selectors,
      get : s::string => properties,
      getAll : s::string => properties,
      remove : unit => unit,
      remove : s::string => unit,
      set : s::string => p::properties => unit
    };
  external jss : jSS =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/jss/index"];
};
