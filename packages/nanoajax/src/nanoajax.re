module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesNanoajaxIndex = {
  type union_of_string_or_formData =
    | String string
    | FormData formData;
  type string_or_formData;
  external string_or_formData : union_of_string_or_formData => string_or_formData =
    "Array.prototype.shift.call" [@@bs.val];
  type requestParameters =
    Js.t {
      ..
      url : string,
      headers : Js.Dict.t string,
      body : string_or_formData,
      method : string,
      cors : Js.boolean
    };
  type callback = Js.t {..};
  external ajax : params::requestParameters => callback::callback => xMLHttpRequest =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/nanoajax/index"];
};
