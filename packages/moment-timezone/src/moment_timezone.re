type momentZone =
  Js.t {
    ..
    name : string,
    abbrs : array string,
    untils : array float,
    offsets : array float,
    abbr : timestamp::float => string,
    offset : timestamp::float => float,
    parse : timestamp::float => float
  };

type momentTimezone =
  Js.t {
    ..
    zone : timezone::string => momentZone,
    add : packedZoneString::string => unit,
    add : packedZoneString::array string => unit,
    link : packedLinkString::string => unit,
    link : packedLinkString::array string => unit,
    load : data::Js.t {.. version : string, links : array string, zones : array string} => unit,
    names : unit => array string,
    guess : unit => string,
    setDefault : timezone::string => unit
  };

type moment =
  Js.t {
    ..
    tz : unit => string,
    tz : timezone::string => moment,
    zoneAbbr : unit => string,
    zoneName : unit => string
  };

external tz : momentTimezone = "" [@@bs.module "moment"];
