type union_of_number_or_date =
  | Number float
  | Date Js.Date.t;

type number_or_date;

external number_or_date : union_of_number_or_date => number_or_date =
  "Array.prototype.shift.call" [@@bs.val];

type union_of_array_number_or_buffer =
  | Array_number (array float)
  | Buffer buffer;

type array_number_or_buffer;

external array_number_or_buffer : union_of_array_number_or_buffer => array_number_or_buffer =
  "Array.prototype.shift.call" [@@bs.val];

external v1 :
  options::Js.t {.. node : array float, clockseq : float, msecs : number_or_date, nsecs : float}? =>
  buffer::array_number_or_buffer? =>
  offset::float? =>
  unit =>
  string =
  "" [@@bs.module "uuid"];

external v4 :
  options::Js.t {.. random : array float, rng : unit => array_number_or_buffer}? =>
  buffer::array_number_or_buffer? =>
  offset::float? =>
  unit =>
  string =
  "" [@@bs.module "uuid"];
