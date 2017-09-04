type tokenRender =
  tokens::array token => index::float => options::'any => env::'any => self::renderer => unit;

type markdownIt =
  Js.t {
    ..
    render : md::string => env::'any? => unit => string,
    renderInline : md::string => env::'any? => unit => string,
    parse : src::string => env::'any => array token,
    parseInline : src::string => env::'any => array token,
    use : plugin::'any => params::array 'any => markdownIt,
    utils :
      Js.t {
        ..
        assign : obj::'any => 'any,
        isString : obj::'any => Js.boolean,
        has : object::'any => key::string => Js.boolean,
        unescapeMd : str::string => string,
        unescapeAll : str::string => string,
        isValidEntityCode : str::'any => Js.boolean,
        fromCodePoint : str::string => string,
        escapeHtml : str::string => string,
        arrayReplaceAt : src::array 'any => pos::float => newElements::array 'any => array 'any,
        isSpace : str::'any => Js.boolean,
        isWhiteSpace : str::'any => Js.boolean,
        isMdAsciiPunct : str::'any => Js.boolean,
        isPunctChar : str::'any => Js.boolean,
        escapeRE : str::string => string,
        normalizeReference : str::string => string
      },
    disable :
      rules::[ | `Array_string (array string) | `String string] [@bs.unwrap] =>
      ignoreInvalid::Js.boolean? =>
      unit =>
      markdownIt,
    enable :
      rules::[ | `Array_string (array string) | `String string] [@bs.unwrap] =>
      ignoreInvalid::Js.boolean? =>
      unit =>
      markdownIt,
    set : options::options => markdownIt,
    normalizeLink : url::string => string,
    normalizeLinkText : url::string => string,
    validateLink : url::string => Js.boolean,
    block : parserBlock,
    core : core,
    helpers : 'any,
    inline : parserInline,
    linkify : linkifyIt,
    renderer : renderer
  };

type options =
  Js.t {
    ..
    html : Js.boolean,
    xhtmlOut : Js.boolean,
    breaks : Js.boolean,
    langPrefix : string,
    linkify : Js.boolean,
    typographer : Js.boolean,
    quotes : string,
    highlight : str::string => lang::string => unit
  };

type linkifyIt = Js.t {.. tlds : lang::string => linkified::Js.boolean => unit};

type renderer =
  Js.t {
    ..
    rules : Js.Dict.t tokenRender,
    render : tokens::array token => options::'any => env::'any => string,
    renderAttrs : token::token => string,
    renderInline : tokens::array token => options::'any => env::'any => string,
    renderToken : tokens::array token => idx::float => options::'any => string
  };

type token =
  Js.t {
    ..
    attrGet : name::string => string_or_null,
    attrIndex : name::string => float,
    attrJoin : name::string => value::string => unit,
    attrPush : attrData::array string => unit,
    attrSet : name::string => value::string => unit,
    attrs : array (array string),
    block : Js.boolean,
    children : array token,
    content : string,
    hidden : Js.boolean,
    info : string,
    level : float,
    map : array float,
    markup : string,
    meta : 'any,
    nesting : float,
    tag : string,
    _type : string
  };

type rule = Js.t {..};

type ruler =
  Js.t {
    ..
    after : afterName::string => ruleName::string => rule::rule => options::'any? => unit => unit,
    at : name::string => rule::rule => options::'any? => unit => unit,
    before :
      beforeName::string => ruleName::string => rule::rule => options::'any? => unit => unit,
    disable :
      rules::[ | `String string | `Array_string (array string)] [@bs.unwrap] =>
      ignoreInvalid::Js.boolean? =>
      unit =>
      array string,
    enable :
      rules::[ | `String string | `Array_string (array string)] [@bs.unwrap] =>
      ignoreInvalid::Js.boolean? =>
      unit =>
      array string,
    enableOnly : rule::string => ignoreInvalid::Js.boolean? => unit => unit,
    getRules : chain::string => array rule,
    push : ruleName::string => rule::rule => options::'any? => unit => unit
  };

type parserBlock =
  Js.t {
    ..
    parse : src::string => md::markdownIt => env::'any => outTokens::array token => unit,
    ruler : ruler
  };

type core = Js.t {.. process : state::'any => unit, ruler : ruler};

type parserInline =
  Js.t {
    ..
    parse : src::string => md::markdownIt => env::'any => outTokens::array token => unit,
    ruler : ruler,
    ruler2 : ruler
  };
