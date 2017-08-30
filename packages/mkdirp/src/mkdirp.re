type union_of_number_or_object =
  | Number float
  | Object (Js.t {.. mode : float, fs : 'any});

type number_or_object;

external number_or_object : union_of_number_or_object => number_or_object =
  "Array.prototype.shift.call" [@@bs.val];

type options = number_or_object;

type callback = err::error? => path::string? => unit => unit;

type union_of_options_or_callback =
  | Options options
  | Callback callback;

type options_or_callback;

external options_or_callback : union_of_options_or_callback => options_or_callback =
  "Array.prototype.shift.call" [@@bs.val];

external mkdirp_apply :
  path::string => options::options_or_callback? => callback::callback? => unit => unit =
  "" [@@bs.module "mkdirp"];

external mkdirp : Js.t {.. sync : path::string => options::options? => unit => unit} =
  "mkdirp" [@@bs.module];
