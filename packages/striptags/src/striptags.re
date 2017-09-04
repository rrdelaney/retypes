type union_of_string_or_array_string =
  | String string
  | Array_string (array string);

type string_or_array_string;

external string_or_array_string : union_of_string_or_array_string => string_or_array_string =
  "Array.prototype.shift.call" [@@bs.val];

external strip : html::string => allowedTags::string_or_array_string? => unit => string =
  "" [@@bs.module "striptags"];
