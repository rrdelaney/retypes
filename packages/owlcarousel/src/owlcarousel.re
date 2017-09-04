module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesOwlcarouselIndex = {
  type union_of_jQuery_or_string =
    | JQuery jQuery
    | String string;
  type jQuery_or_string;
  external jQuery_or_string : union_of_jQuery_or_string => jQuery_or_string =
    "Array.prototype.shift.call" [@@bs.val];
  type iOwlCarouselOptions =
    Js.t {
      ..
      items : float,
      itemsDesktop : array float,
      itemsDesktopSmall : array float,
      itemsTablet : array float,
      itemsTabletSmall : 'any,
      itemsMobile : array float,
      itemsCustom : 'any,
      singleItem : Js.boolean,
      itemsScaleUp : Js.boolean,
      slideSpeed : float,
      paginationSpeed : float,
      rewindSpeed : float,
      autoPlay : 'any,
      stopOnHover : Js.boolean,
      navigation : Js.boolean,
      navigationText : 'any,
      rewindNav : Js.boolean,
      scrollPerPage : Js.boolean,
      pagination : Js.boolean,
      paginationNumbers : Js.boolean,
      responsive : Js.boolean,
      responsiveRefreshRate : float,
      responsiveBaseWidth : jQuery_or_string,
      baseClass : string,
      theme : string,
      lazyLoad : Js.boolean,
      lazyFollow : Js.boolean,
      lazyEffect : 'any,
      autoHeight : Js.boolean,
      jsonPath : 'any,
      jsonSuccess : data::'any => unit,
      dragBeforeAnimFinish : Js.boolean,
      mouseDrag : Js.boolean,
      touchDrag : Js.boolean,
      addClassActive : Js.boolean,
      transitionStyle : 'any,
      beforeUpdate : params::'any? => unit => unit,
      afterUpdate : params::'any? => unit => unit,
      beforeInit : params::'any? => unit => unit,
      afterInit : params::'any? => unit => unit,
      beforeMove : params::'any? => unit => unit,
      afterMove : params::'any? => unit => unit,
      afterAction : params::'any? => unit => unit,
      startDragging : params::'any? => unit => unit,
      afterLazyLoad : params::'any? => unit => unit
    };
  type jQuery = Js.t {.. owlCarousel : options::iOwlCarouselOptions? => unit => jQuery};
};
