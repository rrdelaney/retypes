module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesEvaporateIndex = {
  module Evaporate = {
    type t =
      Js.t {. cancel : (string => Js.boolean) [@bs.meth], add : ('any => string) [@bs.meth]};
    external make : 'any => t =
      "Evaporate"
      [@@bs.new]
      [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/evaporate/index"];
  };
};
