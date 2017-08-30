module ExtendableError = {
  type t = Js.t {.};
  external make : _::unit => t = "ExtendableError" [@@bs.new] [@@bs.module "es6-error"];
};

let es6_error = ExtendableError.make;
