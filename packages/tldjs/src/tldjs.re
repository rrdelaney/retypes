module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesTldjsIndex = {
  external validHosts : array string =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/tldjs/index"];
  external tldExists : host::string => Js.boolean =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/tldjs/index"];
  external getDomain : host::string => string_or_null =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/tldjs/index"];
  external getSubdomain : host::string => string_or_null =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/tldjs/index"];
  external getPublicSuffix : host::string => string_or_null =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/tldjs/index"];
  external isValid : host::string => string_or_null =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/tldjs/index"];
};
