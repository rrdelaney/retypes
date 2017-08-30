type union_of_string_or_func =
  | String string
  | Func (basename::string => string);

type string_or_func;

external string_or_func : union_of_string_or_func => string_or_func =
  "Array.prototype.shift.call" [@@bs.val];

type union_of_string_or_array_string =
  | String string
  | Array_string (array string);

type string_or_array_string;

external string_or_array_string : union_of_string_or_array_string => string_or_array_string =
  "Array.prototype.shift.call" [@@bs.val];

external cpy :
  files::[ | `String string | `Array_string (array string)] [@bs.unwrap] =>
  destination::string =>
  options::
    Js.t {
      ..
      cwd : string,
      parents : Js.boolean,
      rename : string_or_func,
      overwrite : Js.boolean,
      root : string,
      dot : Js.boolean,
      nomount : string,
      mark : Js.boolean,
      nosort : Js.boolean,
      stat : Js.boolean,
      silent : Js.boolean,
      strict : Js.boolean,
      cache : 'any,
      statCache : 'any,
      symlinks : 'any,
      nounique : Js.boolean,
      nonull : Js.boolean,
      debug : Js.boolean,
      nobrace : Js.boolean,
      noglobstar : Js.boolean,
      noext : Js.boolean,
      nocase : Js.boolean,
      matchBase : Js.boolean,
      nodir : Js.boolean,
      ignore : string_or_array_string,
      follow : Js.boolean,
      realpath : Js.boolean,
      absolute : Js.boolean
    }? =>
  unit =>
  Js_promise.t unit =
  "cpy" [@@bs.module];
