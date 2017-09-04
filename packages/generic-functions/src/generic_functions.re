external strcmp : str1::string => str2::string => Js.boolean =
  "" [@@bs.module "generic-functions"];

external icstrcmp : str1::string => str2::string => Js.boolean =
  "" [@@bs.module "generic-functions"];

external strendswith : str::string => suffix::string => Js.boolean =
  "" [@@bs.module "generic-functions"];

external icstrendswith : str::string => suffix::string => Js.boolean =
  "" [@@bs.module "generic-functions"];

external endswithdot : str::string => string = "" [@@bs.module "generic-functions"];

external println : message::string => unit = "" [@@bs.module "generic-functions"];

external printlns : message::array string => unit = "" [@@bs.module "generic-functions"];

external objGetKeyByValue : object::'any => value::'any => string =
  "" [@@bs.module "generic-functions"];
