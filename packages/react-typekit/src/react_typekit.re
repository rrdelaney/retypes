module Typekit = {
  type t = Js.t {. props : Js.t {.. kitId : string}};
  external make : _::unit => t = "Typekit" [@@bs.new] [@@bs.module "react-typekit"];
};

let react_typekit = Typekit.make;
