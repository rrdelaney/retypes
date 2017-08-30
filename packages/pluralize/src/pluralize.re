external pluralize_apply :
  word::string => count::float? => inclusive::Js.boolean? => unit => string =
  "" [@@bs.module "pluralize"];

external pluralize :
  Js.t {
    ..
    addIrregularRule : single::string => plural::string => unit,
    addPluralRule :
      rule::[ | `String string | `Regex Js.Re.t] [@bs.unwrap] => replacemant::string => unit,
    addSingularRule :
      rule::[ | `String string | `Regex Js.Re.t] [@bs.unwrap] => replacemant::string => unit,
    addUncountableRule : ord::[ | `String string | `Regex Js.Re.t] [@bs.unwrap] => unit,
    plural : word::string => string,
    singular : word::string => string
  } =
  "pluralize" [@@bs.module];
