type union_of_error_or_any_1 =
  | Error error
  | Any_1 'any;

type error_or_any_1;

external error_or_any_1 : union_of_error_or_any_1 => error_or_any_1 =
  "Array.prototype.shift.call" [@@bs.val];

type union_of_tty_WriteStream_or_stream_Writable =
  | Tty_WriteStream tty_WriteStream
  | Stream_Writable stream_Writable;

type tty_WriteStream_or_stream_Writable;

external tty_WriteStream_or_stream_Writable :
  union_of_tty_WriteStream_or_stream_Writable => tty_WriteStream_or_stream_Writable =
  "Array.prototype.shift.call" [@@bs.val];

external out_apply : message::string => args::array 'any => unit = "" [@@bs.module "out"];

external out :
  Js.t {
    ..
    error : args::array error_or_any_1 => unit,
    _to : targets::array tty_WriteStream_or_stream_Writable => unit
  } =
  "out" [@@bs.module];
