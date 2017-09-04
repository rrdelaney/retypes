module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesPgwmodalIndex = {
  type pgwModalOption =
    Js.t {
      ..
      content : string,
      target : string,
      url : string,
      title : string,
      titleBar : Js.boolean,
      mainClassName : string,
      backdropClassName : string,
      maxWidth : float,
      angular : Js.boolean,
      modalData : 'any,
      ajaxOptions : 'any,
      closable : Js.boolean,
      closeContent : string,
      closeOnEscape : Js.boolean,
      closeOnBackgroundClick : Js.boolean,
      loadingContent : string,
      errorContent : string,
      pushContent : string
    };
  type pgwModalMethod = Js.t {..};
  type zeptoStatic = Js.t {.. pgwModal : pgwModalMethod};
  type jQueryStatic = Js.t {.. pgwModal : pgwModalMethod};
};
