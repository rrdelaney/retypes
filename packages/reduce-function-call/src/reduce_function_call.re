type callback = body::string => functionIdentifier::string => call::string => 'any;

external reduce_function_call_apply :
  string::string =>
  functionRE::[ | `String string | `Regex Js.Re.t] [@bs.unwrap] =>
  callback::callback =>
  string =
  "" [@@bs.module "reduce_function_call"];

external reduce_function_call : Js.t {..} = "reduce-function-call" [@@bs.module];
