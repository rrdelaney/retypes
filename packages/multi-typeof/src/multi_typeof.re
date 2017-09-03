external multi_typeof :
  input::'any =>
  types::[ | `String string | `Array_string (array string)] [@bs.unwrap] =>
  Js.boolean =
  "multi-typeof" [@@bs.module];
