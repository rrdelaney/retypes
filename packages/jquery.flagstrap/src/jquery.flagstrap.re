type union_of_bool_or_flagStrapPlaceholderOptions =
  | Bool Js.boolean
  | FlagStrapPlaceholderOptions flagStrapPlaceholderOptions;

type bool_or_flagStrapPlaceholderOptions;

external bool_or_flagStrapPlaceholderOptions :
  union_of_bool_or_flagStrapPlaceholderOptions => bool_or_flagStrapPlaceholderOptions =
  "Array.prototype.shift.call" [@@bs.val];

type flagStrapOptions =
  Js.t {
    ..
    inputName : string,
    inputId : string,
    buttonSize : string,
    buttonType : string,
    labelMargin : string,
    scrollable : Js.boolean,
    scrollableHeight : string,
    countries : 'any,
    placeholder : bool_or_flagStrapPlaceholderOptions,
    onSelect : value::'any => element::'any => unit
  };

type flagStrapStatic = Js.t {.. flagStrap : unit};

type flagStrapPlaceholderOptions = Js.t {.. value : string, text : string};
