type configOptions = Js.t {.. _type : string, height : float, width : float};

type matchMediaMock = Js.t {.. setConfig : config::configOptions => unit};

external create : unit => matchMediaMock = "" [@@bs.module "match-media-mock"];
