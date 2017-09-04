type hookerPostHookFunction = result::'any => args::array 'any => iHookerPostHookResult_or_unit;

type hookerPreHookFunction = args::array 'any => iHookerPreHookResult_or_unit;

type union_of_string_or_array_string =
  | String string
  | Array_string (array string);

type string_or_array_string;

external string_or_array_string : union_of_string_or_array_string => string_or_array_string =
  "Array.prototype.shift.call" [@@bs.val];

external hook :
  object::'any =>
  props::[ | `String string | `Array_string (array string)] [@bs.unwrap] =>
  options::iHookerOptions =>
  unit =
  "" [@@bs.module "hooker"];

external unhook : object::'any => props::string_or_array_string? => unit => array string =
  "" [@@bs.module "hooker"];

external orig :
  object::'any => props::[ | `String string | `Array_string (array string)] [@bs.unwrap] => 'any =
  "" [@@bs.module "hooker"];

external override : value::'any => hookerOverride = "" [@@bs.module "hooker"];

external preempt : value::'any => hookerPreempt = "" [@@bs.module "hooker"];

external filter : context::'any => args::array 'any => hookerFilter = "" [@@bs.module "hooker"];
