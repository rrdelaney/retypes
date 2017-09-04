module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesRatyIndex = {
  type jQuery =
    Js.t {
      ..
      raty : unit => jQuery,
      raty : options::jQueryRatyOptions => jQuery,
      raty : method::string => parameter::'any => 'any,
      raty : method::score => float,
      raty : method::score => score::float => unit,
      raty : method::click => star::float => unit,
      raty : method::readonly => on::Js.boolean => unit,
      raty : method::cancel => on::Js.boolean => unit,
      raty : method::reload => unit,
      raty : method::set => options::jQueryRatyOptions => unit,
      raty : method::destroy => jQuery,
      raty : method::move => number::float => unit
    };
  type jQueryRatyOptions =
    Js.t {
      ..
      cancel : Js.boolean,
      cancelClass : string,
      cancelHint : string,
      cancelOff : string,
      cancelOn : string,
      cancelPlace : string,
      click : score::float => event::jQueryEventObject => unit,
      half : Js.boolean,
      halfShow : Js.boolean,
      hints : array string,
      iconRange : array (array 'any),
      mouseout : score::float => event::jQueryEventObject => unit,
      mouseover : score::float => event::jQueryEventObject => unit,
      noRatedMsg : string,
      number : float,
      numberMax : float,
      path : string,
      precision : Js.boolean,
      readOnly : Js.boolean,
      round : jQueryRatyRoundingOptions,
      score : float,
      scoreName : string,
      single : Js.boolean,
      space : Js.boolean,
      starHalf : string,
      starOff : string,
      starOn : string,
      target : string,
      targetFormat : string,
      targetKeep : Js.boolean,
      targetScore : string,
      targetText : string,
      targetType : string,
      starType : string
    };
  type jQueryRatyRoundingOptions = Js.t {.. down : float, full : float, up : float};
};
