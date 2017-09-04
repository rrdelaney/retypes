external areaSelect : box::areaSelectOptions => areaSelect = "" [@@bs.module "leaflet"];

type areaSelectOptions = Js.t {.. width : float, height : float, keepAspectRatio : Js.boolean};

type dimension = Js.t {.. width : float, height : float};

type areaSelect =
  Js.t {
    ..
    addTo : map::map => map,
    getBounds : unit => latLngBounds,
    remove : unit => unit,
    setDimensions : dim::dimension => unit
  };
