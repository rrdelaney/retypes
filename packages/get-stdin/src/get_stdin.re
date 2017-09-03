external get_stdin_apply : unit => Js_promise.t string = "" [@@bs.module "get_stdin"];

external get_stdin : Js.t {.. buffer : unit => Js_promise.t buffer} = "get-stdin" [@@bs.module];
