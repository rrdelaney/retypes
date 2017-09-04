external apply : target::'any => patch::'any => 'any = "" [@@bs.module "json-merge-patch"];

external generate : before::'any => after::'any => 'any = "" [@@bs.module "json-merge-patch"];

external merge : patch1::'any => patch2::'any => 'any = "" [@@bs.module "json-merge-patch"];
