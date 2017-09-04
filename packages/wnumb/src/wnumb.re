module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesWnumbIndex = {
  external wNumb : wNumb =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/wnumb/index"];
  type wNumbOptions =
    Js.t {
      ..
      decimals : float,
      mark : string,
      thousand : string,
      prefix : string,
      postfix : string,
      negative : string,
      negativeBefore : string,
      encoder : value::float => float,
      decoder : value::float => float,
      edit : value::float => float,
      undo : value::float => float
    };
  type wNumb = Js.t {..};
  type wNumbInstance = Js.t {.. _to : val::float => string, from : val::string => float};
};
