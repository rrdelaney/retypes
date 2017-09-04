module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesSpatialiteIndex = {
  module Database = {
    type t = Js.t {. spatialite : (err::error => unit => unit) [@bs.meth]};
    external make : _::unit => t =
      "Database"
      [@@bs.new]
      [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/spatialite/index"];
  };
};
