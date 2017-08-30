type jasmineExpectType =
  Js.t {
    ..
    not : jasmineExpectType,
    toBe : value::'any => unit,
    toBeCloseTo : num::float => delta::'any => unit,
    toBeDefined : unit => unit,
    toBeFalsy : unit => unit,
    toBeGreaterThan : number::float => unit,
    toBeLessThan : number::float => unit,
    toBeNull : unit => unit,
    toBeTruthy : unit => unit,
    toBeUndefined : unit => unit,
    toContain : str::string => unit,
    toEqual : value::'any => unit,
    toHaveBeenCalled : unit => unit,
    toHaveBeenCalledTimes : number::float => unit,
    toHaveBeenCalledWith : args::array 'any => unit,
    toMatch : regexp::Js.Re.t => unit,
    toThrow : message::string? => unit => unit,
    toThrowError : val::'any => unit
  };

type jasmineCallsType =
  Js.t {
    ..
    allArgs : unit => 'any,
    all : unit => 'any,
    mostRecent : unit => 'any,
    first : unit => 'any,
    any : unit => Js.boolean,
    count : unit => float,
    reset : unit => unit
  };

type jasmineSpyType = Js.t {.. calls : jasmineCallsType};

type jasmineClockType =
  Js.t {
    ..
    install : unit => unit,
    uninstall : unit => unit,
    tick : milliseconds::float? => unit => unit,
    mockDate : date::Js.Date.t => unit
  };
