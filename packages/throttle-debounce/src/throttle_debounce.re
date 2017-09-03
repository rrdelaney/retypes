external throttle :
  delay::float =>
  noTrailing::Js.boolean =>
  callback::unit =>
  't =>
  debounceMode::Js.boolean =>
  unit =>
  't =
  "" [@@bs.module "throttle-debounce"];

external throttle : delay::float => noTrailing::Js.boolean => callback::unit => 't => unit => 't =
  "" [@@bs.module "throttle-debounce"];

external throttle : delay::float => callback::unit => 't => debounceMode::Js.boolean => unit => 't =
  "" [@@bs.module "throttle-debounce"];

external throttle : delay::float => callback::unit => 't => unit => 't =
  "" [@@bs.module "throttle-debounce"];

external debounce : delay::float => atBegin::Js.boolean => callback::unit => 't => unit => 't =
  "" [@@bs.module "throttle-debounce"];

external debounce : delay::float => callback::unit => 't => unit => 't =
  "" [@@bs.module "throttle-debounce"];
