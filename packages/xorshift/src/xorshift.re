module XorShift = {
  type t =
    Js.t {. random : (unit => float) [@bs.meth], randomint : (unit => (float, float)) [@bs.meth]};
  external make : (float, float, float, float) => t =
    "XorShift" [@@bs.new] [@@bs.module "xorshift"];
};

external xorshift : XorShift.t = "xorshift" [@@bs.module];
