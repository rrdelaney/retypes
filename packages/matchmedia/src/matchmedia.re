type typeValue =
  [
    | `all
    | `aural
    | `braille
    | `embossed
    | `grid
    | `handheld
    | `print
    | `projection
    | `screen
    | `tty
    | `tv
  ]
  [@bs.string];

type orientationValue = [ | `portait | `landscape] [@bs.string];

type scanValue = [ | `interlace | `progressive] [@bs.string];

type union_of_number_or_bool =
  | Number float
  | Bool Js.boolean;

type number_or_bool;

external number_or_bool : union_of_number_or_bool => number_or_bool =
  "Array.prototype.shift.call" [@@bs.val];

type values =
  Js.t {
    ..
    _type : typeValue,
    aspect_ratio : string,
    width : string,
    height : string,
    orientation : orientationValue,
    device_width : string,
    device_height : string,
    device_aspect_ratio : string,
    color : number_or_bool,
    color_index : number_or_bool,
    monochrome : number_or_bool,
    resolution : string,
    scan : scanValue,
    grid : number_or_bool
  };

type mediaQueryListListener = list::mediaQueryList => unit;

type mediaQueryList =
  Js.t {
    ..
    addListener : listener::mediaQueryListListener => unit,
    removeListener : listener::mediaQueryListListener => unit,
    matches : Js.boolean,
    media : string
  };

external exports : query::string => values::values? => unit => mediaQueryList =
  "" [@@bs.module "matchmedia"];
