type union_of_number_or_bool =
  | Number float
  | Bool Js.boolean;

type number_or_bool;

external number_or_bool : union_of_number_or_bool => number_or_bool =
  "Array.prototype.shift.call" [@@bs.val];

type union_of_string_or_array_string_or_dict_any_1 =
  | String string
  | Array_string (array string)
  | Dict_any_1 (Js.Dict.t 'any);

type string_or_array_string_or_dict_any_1;

external string_or_array_string_or_dict_any_1 :
  union_of_string_or_array_string_or_dict_any_1 => string_or_array_string_or_dict_any_1 =
  "Array.prototype.shift.call" [@@bs.val];

type options =
  Js.t {
    ..
    checkDNS : Js.boolean,
    errorLevel : number_or_bool,
    tldBlacklist : string_or_array_string_or_dict_any_1,
    tldWhitelist : string_or_array_string_or_dict_any_1,
    minDomainAtoms : float
  };

type callback = result::[ | `Bool Js.boolean | `Number float] [@bs.unwrap] => unit;

type union_of_options_or_callback =
  | Options options
  | Callback callback;

type options_or_callback;

external options_or_callback : union_of_options_or_callback => options_or_callback =
  "Array.prototype.shift.call" [@@bs.val];

external isemail :
  Js.t {
    ..
    validate :
      email::string =>
      options::options_or_callback? =>
      callback::callback? =>
      unit =>
      bool_or_number_or_unit
  } =
  "isemail" [@@bs.module];
