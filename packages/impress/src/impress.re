module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesImpressIndex = {
  type impress =
    Js.t {
      ..
      init : unit => unit,
      getStep : step::'any => 'any,
      goto : element::'any => duration::float? => unit => 'any,
      prev : unit => 'any,
      next : unit => 'any
    };
  external impress : unit => impress =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/impress/index"];
};
