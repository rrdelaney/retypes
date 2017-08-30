type union_of_string_or_bool =
  | String string
  | Bool Js.boolean;

type string_or_bool;

external string_or_bool : union_of_string_or_bool => string_or_bool =
  "Array.prototype.shift.call" [@@bs.val];

type union_of_string_or_object =
  | String string
  | Object 'any;

type string_or_object;

external string_or_object : union_of_string_or_object => string_or_object =
  "Array.prototype.shift.call" [@@bs.val];

type union_of_string_or_array_string_or_object =
  | String string
  | Array_string (array string)
  | Object (
      Js.t {
        ..
        description : string,
        help : string,
        version : string_or_bool,
        pkg : string_or_object,
        argv : array string,
        inferType : Js.boolean
      }
    );

type string_or_array_string_or_object;

external string_or_array_string_or_object :
  union_of_string_or_array_string_or_object => string_or_array_string_or_object =
  "Array.prototype.shift.call" [@@bs.val];

type options = string_or_array_string_or_object;

type union_of_string_or_array_string =
  | String string
  | Array_string (array string);

type string_or_array_string;

external string_or_array_string : union_of_string_or_array_string => string_or_array_string =
  "Array.prototype.shift.call" [@@bs.val];

type union_of_bool_or_string_or_array_string =
  | Bool Js.boolean
  | String string
  | Array_string (array string);

type bool_or_string_or_array_string;

external bool_or_string_or_array_string :
  union_of_bool_or_string_or_array_string => bool_or_string_or_array_string =
  "Array.prototype.shift.call" [@@bs.val];

type minimistOptions =
  Js.t {
    ..
    string : string_or_array_string,
    boolean : bool_or_string_or_array_string,
    alias : Js.Dict.t string_or_array_string,
    default : Js.Dict.t 'any,
    stopEarly : Js.boolean,
    unknown : param::string => Js.boolean
  };

external meow :
  options::options =>
  minimistOptions::minimistOptions? =>
  unit =>
  Js.t {
    ..
    input : array string,
    flags : Js.Dict.t string_or_bool,
    pkg : 'any,
    help : string,
    showHelp : 'any
  } =
  "meow" [@@bs.module];
