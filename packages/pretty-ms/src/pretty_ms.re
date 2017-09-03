type options =
  Js.t {
    ..
    secDecimalDigits : float, msDecimalDigits : float, compact : Js.boolean, verbose : Js.boolean
  };

external pretty_ms : ms::float => opts::options? => unit => string = "pretty-ms" [@@bs.module];
