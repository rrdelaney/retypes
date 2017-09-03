external path_is_absolute_apply : filePath::string => Js.boolean =
  "" [@@bs.module "path_is_absolute"];

external path_is_absolute :
  Js.t {.. posix : filePath::string => Js.boolean, win32 : filePath::string => Js.boolean} =
  "path-is-absolute" [@@bs.module];
