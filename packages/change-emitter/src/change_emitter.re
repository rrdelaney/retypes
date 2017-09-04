type unlisten = unit => unit;

type listener = args::array 'any => unit;

type listenerOf0 = unit => unit;

type listenerOf1 't = value::'t => unit;

type listenerOf2 't1 't2 = value1::'t1 => value2::'t2 => unit;

type listenerOf3 't1 't2 't3 = value1::'t1 => value2::'t2 => value3::'t3 => unit;

type listenerOf4 't1 't2 't3 't4 =
  value1::'t1 => value2::'t2 => value3::'t3 => value4::'t4 => unit;

type listenerOf5 't1 't2 't3 't4 't5 =
  value1::'t1 => value2::'t2 => value3::'t3 => value4::'t4 => value5::'t5 => unit;

type changeEmitter =
  Js.t {.. listen : listener::listener => unlisten, emit : args::array 'any => unit};

type changeEmitterOf1 't =
  Js.t {.. listen : listener::listenerOf1 't => unlisten, emit : value::'t => unit};

type changeEmitterOf0 = Js.t {.. listen : listener::listenerOf0 => unlisten, emit : unit => unit};

type changeEmitterOf2 't1 't2 =
  Js.t {
    ..
    listen : listener::listenerOf2 't1 't2 => unlisten, emit : value1::'t1 => value2::'t2 => unit
  };

type changeEmitterOf3 't1 't2 't3 =
  Js.t {
    ..
    listen : listener::listenerOf3 't1 't2 't3 => unlisten,
    emit : value1::'t1 => value2::'t2 => value3::'t3 => unit
  };

type changeEmitterOf4 't1 't2 't3 't4 =
  Js.t {
    ..
    listen : listener::listenerOf4 't1 't2 't3 't4 => unlisten,
    emit : value1::'t1 => value2::'t2 => value3::'t3 => value4::'t4 => unit
  };

type changeEmitterOf5 't1 't2 't3 't4 't5 =
  Js.t {
    ..
    listen : listener::listenerOf5 't1 't2 't3 't4 't5 => unlisten,
    emit : value1::'t1 => value2::'t2 => value3::'t3 => value4::'t4 => value5::'t5 => unit
  };

external createChangeEmitter : unit => changeEmitter = "" [@@bs.module "change-emitter"];
