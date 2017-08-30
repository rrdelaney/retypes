type options = Js.t {.. debug : Js.boolean, message : string};

external copy_to_clipboard : text::string => options::options? => unit => Js.boolean =
  "copy-to-clipboard" [@@bs.module];
