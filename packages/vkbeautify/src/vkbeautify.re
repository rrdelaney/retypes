module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesVkbeautifyIndex = {
  type union_of_number_or_string =
    | Number float
    | String string;
  type number_or_string;
  external number_or_string : union_of_number_or_string => number_or_string =
    "Array.prototype.shift.call" [@@bs.val];
  external xml : text::string => amountOfWhitespaces::number_or_string? => unit => string =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/vkbeautify/index"];
  external json : text::string => amountOfWhitespaces::number_or_string? => unit => string =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/vkbeautify/index"];
  external css : text::string => amountOfWhitespaces::number_or_string? => unit => string =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/vkbeautify/index"];
  external sql : text::string => amountOfWhitespaces::number_or_string? => unit => string =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/vkbeautify/index"];
  external xmlmin : text::string => preserveComments::Js.boolean? => unit => string =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/vkbeautify/index"];
  external jsonmin : text::string => string =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/vkbeautify/index"];
  external cssmin : text::string => preserveComments::Js.boolean? => unit => string =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/vkbeautify/index"];
  external sqlmin : text::string => string =
    "" [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/vkbeautify/index"];
};
