type people =
  Js.t {
    ..
    set :
      prop::[ | `Object 'any | `String string] [@bs.unwrap] =>
      to::'any? =>
      callback::'any? =>
      unit =>
      unit,
    set_once :
      prop::[ | `Object 'any | `String string] [@bs.unwrap] =>
      to::'any? =>
      callback::'any? =>
      unit =>
      unit,
    increment :
      prop::[ | `Object 'any | `String string] [@bs.unwrap] =>
      by::float? =>
      callback::'any? =>
      unit =>
      unit,
    append :
      prop::[ | `Object 'any | `String string] [@bs.unwrap] =>
      value::'any? =>
      callback::'any? =>
      unit =>
      unit,
    union :
      prop::[ | `Object 'any | `String string] [@bs.unwrap] =>
      value::'any? =>
      callback::'any? =>
      unit =>
      unit,
    track_charge : amount::float => properties::'any? => callback::'any? => unit => unit,
    clear_charges : callback::'any? => unit => unit,
    delete_user : unit => unit
  };

type union_of_object_or_function =
  | Object 'any
  | Function 'any;

type object_or_function;

external object_or_function : union_of_object_or_function => object_or_function =
  "Array.prototype.shift.call" [@@bs.val];

type mixpanelBrowser =
  Js.t {
    ..
    init : token::string => config::'any? => name::string? => unit => unit,
    push : item::(string, 'any) => unit,
    disable : events::array string? => unit => unit,
    track : event_name::string => properties::'any? => callback::'any? => unit => unit,
    track_links :
      query::[ | `Object 'any | `String string] [@bs.unwrap] =>
      event_name::string =>
      properties::object_or_function? =>
      unit =>
      unit,
    track_forms :
      query::[ | `Object 'any | `String string] [@bs.unwrap] =>
      event_name::string =>
      properties::object_or_function? =>
      unit =>
      unit,
    time_event : event_name::string => unit,
    register : properties::'any => days::float? => unit => unit,
    register_once : properties::'any => default_value::'any? => days::float? => unit => unit,
    unregister : property::string => unit,
    identify : unique_id::string => unit,
    reset : unit => unit,
    get_distinct_id : unit => string,
    alias : alias::string => original::string? => unit => unit,
    set_config : config::'any => unit,
    get_config : unit => 'any,
    people : people
  };

external mixpanel_browser : mixpanelBrowser = "mixpanel-browser" [@@bs.module];
