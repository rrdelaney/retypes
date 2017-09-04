module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesJsurlIndex = {
  type urlQuery = Js.t {.. clear : unit => unit};
  module Url = {
    type t 't =
      Js.t {
        .
        query : 't,
        protocol : string,
        user : string,
        pass : string,
        host : string,
        port : string,
        path : string,
        hash : string,
        href : string,
        toString : (unit => string) [@bs.meth]
      };
    external make : unit => t =
      "Url"
      [@@bs.new]
      [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/jsurl/index"];
  };
};
