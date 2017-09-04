module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesKeytarIndex = {
  external getPassword : service::string => account::string => Js_promise.t string_or_null =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/keytar/index"];
  external setPassword :
    service::string => account::string => password::string => Js_promise.t unit =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/keytar/index"];
  external deletePassword : service::string => account::string => Js_promise.t Js.boolean =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/keytar/index"];
  external findPassword : service::string => Js_promise.t string_or_null =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/keytar/index"];
};
