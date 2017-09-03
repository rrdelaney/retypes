external isomorphic_fetch :
  input::[ | `String string | `Request request | `URL uRL] [@bs.unwrap] =>
  init::requestOptions? =>
  unit =>
  Js_promise.t response =
  "isomorphic-fetch" [@@bs.module];
