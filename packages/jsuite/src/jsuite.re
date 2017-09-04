external getVersion : unit => string = "" [@@bs.module "jSuite"];

external setLogging : toggle::Js.boolean => unit = "" [@@bs.module "jSuite"];

external getRoleCenter : unit => 'any = "" [@@bs.module "jSuite"];

external getUser : unit => 'any = "" [@@bs.module "jSuite"];

external getScriptParameter : paramName::string => 'any = "" [@@bs.module "jSuite"];

external getDeploymentId : unit => 'any = "" [@@bs.module "jSuite"];

external getScriptId : unit => 'any = "" [@@bs.module "jSuite"];

external isProduction : unit => 'any = "" [@@bs.module "jSuite"];

external clearSublist : transaction::nlobjRecord => listType::string => unit =
  "" [@@bs.module "jSuite"];

external getCompanyPreference : paramName::string => 'any = "" [@@bs.module "jSuite"];

external roundNum : num::float => length::float => float = "" [@@bs.module "jSuite"];

external isNumber : n::'any => Js.boolean = "" [@@bs.module "jSuite"];

external runSearch : config::iconfig? => unit => 'any = "" [@@bs.module "jSuite"];

external lookupField : dataIn::'any => string = "" [@@bs.module "jSuite"];

external submitField : dataIn::'any => 'any = "" [@@bs.module "jSuite"];

external asyncLookupField : config::'any => callback::'any => unit = "" [@@bs.module "jSuite"];

external asyncSubmitField : config::'any => jQueryXHR = "" [@@bs.module "jSuite"];

external audit : title::string => message::string => unit = "" [@@bs.module "jSuite"];

external debug : title::string => message::string => unit = "" [@@bs.module "jSuite"];

external error : title::string => message::string => unit = "" [@@bs.module "jSuite"];

external emergency : title::string => message::string => unit = "" [@@bs.module "jSuite"];
