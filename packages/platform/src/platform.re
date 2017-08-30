module Platform = {
  type t =
    Js.t {
      .
      toString : (unit => string) [@bs.meth],
      parse : (string => Platform.t) [@bs.meth],
      description : string,
      layout : string,
      manufacturer : string,
      name : string,
      prerelease : string,
      product : string,
      ua : string,
      version : string,
      os :
        Js.t {
          ..
          toString : unit => string, architecture : float, version : string, family : string
        }
    };
  external make : _::unit => t = "Platform" [@@bs.new] [@@bs.module "platform"];
};

external platform : Platform.t = "platform" [@@bs.module];
