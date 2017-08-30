type options =
  Js.t {
    ..
    async : Js.boolean, attrs : Js.Dict.t 'any, charset : string, text : string, _type : string
  };

type callback = err::error? => el::hTMLScriptElement => unit => unit_or_any_1;

type loadScript = Js.t {..};

external load_script : loadScript = "load-script" [@@bs.module];
