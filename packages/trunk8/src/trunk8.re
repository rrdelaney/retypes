module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesTrunk8Index = {
  type trunk8Options =
    Js.t {.. fill : string, lines : float, side : string, tooltip : Js.boolean, width : string};
  type jQuery =
    Js.t {
      ..
      trunk8 : method::string => value::string? => unit => 'any,
      trunk8 : options::trunk8Options? => unit => 'any
    };
};
