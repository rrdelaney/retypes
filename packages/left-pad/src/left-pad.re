type union_of_string_or_number =
  | String string
  | Number float;

type string_or_number;

external string_or_number : union_of_string_or_number => string_or_number =
  "Array.prototype.shift.call" [@@bs.val];

external left_pad : str::string => len::float => ch::string_or_number? => unit => string =
  "left-pad" [@@bs.module];
