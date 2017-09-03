type checkstyleMessage =
  Js.t {
    ..
    line : float, column : float, severity : [ | `error | `warning] [@bs.string], message : string
  };

type checkstyleFileResult = Js.t {.. filename : string, messages : array checkstyleMessage};

type checkstyleResult = array checkstyleFileResult;

external checkstyle_formatter : result::checkstyleResult => string =
  "checkstyle-formatter" [@@bs.module];
