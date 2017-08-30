type shortIdModule =
  Js.t {
    ..
    generate : unit => string,
    seed : seed::float => shortIdModule,
    worker : workerId::float => shortIdModule,
    characters : characters::string => string,
    decode : id::string => Js.t {.. version : float, worker : float},
    isValid : id::'any => Js.boolean
  };

external shortid : shortIdModule = "shortid" [@@bs.module];
