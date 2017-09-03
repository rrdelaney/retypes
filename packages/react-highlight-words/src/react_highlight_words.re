type props =
  Js.t {
    ..
    autoEscape : Js.boolean,
    highlightClassName : string,
    highlightStyle : 'any,
    sanitize : 'any,
    searchWords : array string,
    textToHighlight : string
  };

module ReactHighlightedWords = {
  type t = Js.t {. props : props};
  external make : _::unit => t =
    "ReactHighlightedWords" [@@bs.new] [@@bs.module "react-highlight-words"];
};

let react_highlight_words = ReactHighlightedWords.make;
