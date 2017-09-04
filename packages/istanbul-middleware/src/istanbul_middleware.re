type matcher = file::string => Js.boolean;

type postLoadHookFn = file::'any => Js.t {..};

type postLoadHook =
  matcherfn::matcher => transformer::'any => verbose::Js.boolean => postLoadHookFn;

type clientMatcher = req::request => Js.boolean;

type pathTransformer = req::request => string;

external hookLoader :
  matcherOrRoot::[ | `Matcher matcher | `String string] [@bs.unwrap] =>
  opts::Js.t {.. postLoadHook : postLoadHook, verbose : Js.boolean}? =>
  unit =>
  unit =
  "" [@@bs.module "istanbul-middleware"];

external createHandler : opts::Js.t {.. resetOnGet : Js.boolean}? => unit => 'any =
  "" [@@bs.module "istanbul-middleware"];

external createClientHandler :
  root::string =>
  opts::Js.t {.. matcher : clientMatcher, pathTransformer : pathTransformer, verbose : Js.boolean}? =>
  unit =>
  'any =
  "" [@@bs.module "istanbul-middleware"];
