type transform = body::Js.t {..} => request::request => response::response => 'any;

type transformHeader = body::incomingMessage => request::request => response::response => 'any;

external json : fn::transform => 'any = "" [@@bs.module "express-mung"];

external jsonAsync : fn::transform => promiseLike 'any = "" [@@bs.module "express-mung"];

external headers : fn::transformHeader => 'any = "" [@@bs.module "express-mung"];

external headersAsync : fn::transformHeader => promiseLike 'any = "" [@@bs.module "express-mung"];
