type debugger = Js.t {.. enabled : Js.boolean, log : unit => Js.t {..}, namespace : string};

external exports : namespace::string => debugger = "" [@@bs.module "debug"];

external names : array string = "" [@@bs.module "debug"];

external skips : array string = "" [@@bs.module "debug"];

external colors : array float = "" [@@bs.module "debug"];

external disable : unit => unit = "" [@@bs.module "debug"];

external enable : namespaces::string => unit = "" [@@bs.module "debug"];

external enabled : name::string => Js.boolean = "" [@@bs.module "debug"];

external humanize : unit => unit = "" [@@bs.module "debug"];

external useColors : unit => Js.boolean = "" [@@bs.module "debug"];

external log : unit => unit = "" [@@bs.module "debug"];

external formatters : Js.Dict.t (unit => Js.t {..}) = "" [@@bs.module "debug"];
