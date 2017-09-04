type config =
  Js.t {
    ..
    batchEvents : Js.boolean,
    cookieExpiration : float,
    cookieName : string,
    deviceId : string,
    domain : string,
    eventUploadPeriodMillis : float,
    eventUploadThreshold : float,
    includeReferrer : Js.boolean,
    includeUtm : Js.boolean,
    language : string,
    optOut : Js.boolean,
    platform : string,
    saveEvents : Js.boolean,
    savedMaxCount : float,
    sessionTimeout : float,
    uploadBatchSize : float
  };

module Identify = {
  type t =
    Js.t {
      .
      set : (string => 'any => Identify.t) [@bs.meth],
      setOnce : (string => 'any => Identify.t) [@bs.meth],
      add : (string => float => Identify.t) [@bs.meth],
      append : (string => 'any => Identify.t) [@bs.meth],
      prepend : (string => 'any => Identify.t) [@bs.meth],
      unset : (string => Identify.t) [@bs.meth]
    };
  external make : _::unit => t = "Identify" [@@bs.new] [@@bs.module "amplitude"];
};

external init : apiKey::string => unit = "" [@@bs.module "amplitude"];

external setVersionName : version::string => unit = "" [@@bs.module "amplitude"];

external setUserId : userId::string => unit = "" [@@bs.module "amplitude"];

external setDeviceId : id::string => unit = "" [@@bs.module "amplitude"];

external regenerateDeviceId : unit => unit = "" [@@bs.module "amplitude"];

external identify : identify::Identify.t => unit = "" [@@bs.module "amplitude"];

external setUserProperties : properties::'any => unit = "" [@@bs.module "amplitude"];

external clearUserProperties : unit => unit = "" [@@bs.module "amplitude"];

external setOptOut : optOut::Js.boolean => unit = "" [@@bs.module "amplitude"];

external setGroup :
  groupType::string =>
  groupName::[ | `String string | `Array_string (array string)] [@bs.unwrap] =>
  unit =
  "" [@@bs.module "amplitude"];

external logEvent : event::string => unit = "" [@@bs.module "amplitude"];

external options : config = "" [@@bs.module "amplitude"];
