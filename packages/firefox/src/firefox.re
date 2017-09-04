module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesFirefoxIndex = {
  type navigator = Js.t {.. mozApps : apps};
  type apps =
    Js.t {
      ..
      install : url::string => receipts::array 'any? => unit => dOMRequest app,
      getSelf : unit => dOMRequest app,
      getInstalled : unit => dOMRequest array app,
      checkInstalled : url::string => dOMRequest app
    };
  type dOMRequest 't =
    Js.t {.. onsuccess : 'any, onerror : 'any, readyState : string, result : 't, error : dOMError};
  type app =
    Js.t {
      ..
      manifest : 'any,
      manifestURL : string,
      origin : string,
      installOrigin : string,
      installTime : float,
      receipts : array 'any,
      launch : unit => unit,
      checkForUpdate : unit => dOMRequest 'any
    };
};
