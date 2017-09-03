external path_exists_apply : filePath::string => Js_promise.t Js.boolean =
  "" [@@bs.module "path_exists"];

external path_exists : Js.t {.. sync : filePath::string => Js.boolean} =
  "path-exists" [@@bs.module];
