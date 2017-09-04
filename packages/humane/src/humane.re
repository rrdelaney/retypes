module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesHumaneIndex = {
  type humaneOptions =
    Js.t {
      ..
      queue : array string,
      baseCls : string,
      addnCls : string,
      timeout : float,
      waitForMove : Js.boolean,
      clickToClose : Js.boolean,
      forceNew : Js.boolean
    };
  type humane =
    Js.t {
      ..
      queue : array string,
      baseCls : string,
      addnCls : string,
      timeout : float,
      waitForMove : Js.boolean,
      clickToClose : Js.boolean,
      forceNew : Js.boolean,
      create : options::humaneOptions? => unit => humane,
      info : 'any,
      error : 'any,
      spawn : options::humaneOptions => 'any,
      remove : x::'any => unit,
      log : message::string => humane,
      log : message::string => callback::'any => humane,
      log : message::string => options::humaneOptions => humane,
      log : message::string => callback::'any => options::humaneOptions => humane,
      log : listOfMessages::array 'any => humane
    };
  external humane : humane =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/humane/index"];
};
