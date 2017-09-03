external file_type :
  buffer::[ | `Buffer buffer | `Uint8Array uint8Array] [@bs.unwrap] =>
  Js.t {.. ext : string, mime : string} =
  "file-type" [@@bs.module];
