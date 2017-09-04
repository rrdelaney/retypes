type union_of_round_or_ceil_or_floor =
  | Round round
  | Ceil ceil
  | Floor floor;

type round_or_ceil_or_floor;

external round_or_ceil_or_floor : union_of_round_or_ceil_or_floor => round_or_ceil_or_floor =
  "Array.prototype.shift.call" [@@bs.val];

type moment =
  Js.t {
    ..
    round :
      precision::float => key::string => direction::round_or_ceil_or_floor? => unit => moment,
    ceil : precision::float => key::string => moment,
    floor : precision::float => key::string => moment
  };
