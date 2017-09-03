module PrettyError = {
  type t =
    Js.t {
      .
      start : (unit => unit) [@bs.meth],
      alias : (string => string => unit) [@bs.meth],
      appendStyle : ('any => unit) [@bs.meth],
      render : (error => unit) [@bs.meth],
      skip : (traceline::'any => lineNumber::float => Js.boolean => unit) [@bs.meth],
      skipNodeFiles : (unit => unit) [@bs.meth],
      skipPackage : (packages::array string => unit) [@bs.meth],
      skipPath : (string => unit) [@bs.meth],
      start : (unit => unit) [@bs.meth],
      withoutColors : (unit => unit) [@bs.meth]
    };
  external make : unit => t = "PrettyError" [@@bs.new] [@@bs.module "pretty-error"];
};

let pretty_error = PrettyError.make;
