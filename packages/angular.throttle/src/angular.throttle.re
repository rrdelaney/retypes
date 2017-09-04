type iAngularStatic =
  Js.t {
    ..
    throttle :
      fn::'any =>
      throttle::float =>
      options::Js.t {.. leading : Js.boolean, trailing : Js.boolean}? =>
      unit =>
      'any
  };
