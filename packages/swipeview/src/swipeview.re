module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesSwipeviewIndex = {
  type swipeViewEvent = Js.t {..};
  type swipeViewOptions =
    Js.t {
      ..
      text : string,
      numberOfPages : float,
      snapThreshold : float,
      hastyPageFlip : Js.boolean,
      loop : Js.boolean
    };
  module SwipeView = {
    type t =
      Js.t {
        .
        masterPages : array hTMLElement,
        currentMasterPage : float,
        wrapper : hTMLElement,
        slider : hTMLElement,
        destroy : (unit => unit) [@bs.meth],
        refreshSize : (unit => unit) [@bs.meth],
        updatePageCount : (float => unit) [@bs.meth],
        goToPage : (float => unit) [@bs.meth],
        next : (unit => unit) [@bs.meth],
        prev : (unit => unit) [@bs.meth],
        handleEvent : (event => unit) [@bs.meth],
        onFlip : swipeViewEvent,
        onMoveOut : swipeViewEvent,
        onMoveIn : swipeViewEvent,
        onTouchStart : swipeViewEvent,
        wrapperHeight : float
      };
    external make : string => t =
      "SwipeView"
      [@@bs.new]
      [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/swipeview/index"];
  };
};
