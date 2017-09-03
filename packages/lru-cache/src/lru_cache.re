type lRUCache 'k 'v =
  Js.t {
    ..
    set : key::'k => value::'v => maxAge::float? => unit => unit,
    get : key::'k => 'v,
    peek : key::'k => 'v,
    del : key::'k => unit,
    reset : unit => unit,
    has : key::'k => Js.boolean
  };

type options 'k 'v =
  Js.t {
    ..
    max : float,
    maxAge : float,
    length : value::'v => key::'k => float,
    dispose : key::'k => value::'v => unit,
    stale : Js.boolean
  };

external lru_cache : options::options 'k 'v => lRUCache 'k 'v = "lru-cache" [@@bs.module];
