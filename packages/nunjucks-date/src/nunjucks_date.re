external setDefaultFormat : formatString::string => unit = "" [@@bs.module "nunjucks-date"];

external install : env::'any => filterName::string? => unit => unit =
  "" [@@bs.module "nunjucks-date"];
