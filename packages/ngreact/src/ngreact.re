type reactDirective =
  reactComponentName::[ | `String string | `ComponentClass componentClass] [@bs.unwrap] =>
  propNames::array string? =>
  conf::'any? =>
  injectableProps::'any? =>
  unit =>
  iDirective;
