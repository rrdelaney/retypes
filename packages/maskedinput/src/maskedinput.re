module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesMaskedinputIndex = {
  type jQueryMaskedInputOptions =
    Js.t {
      ..
      mask : string,
      alias : string,
      placeholder : string,
      repeat : float,
      greedy : Js.boolean,
      skipOptionalPartCharacter : string,
      clearIncomplete : Js.boolean,
      clearMaskOnLostFocus : Js.boolean,
      autoUnmask : Js.boolean,
      showMaskOnFocus : Js.boolean,
      showMaskOnHover : Js.boolean,
      showToolTip : Js.boolean,
      isComplete : buffer::'any => options::'any => Js.t {..},
      numeric : Js.boolean,
      radixPoint : string,
      rightAlignNumerics : Js.boolean,
      oncomplete : value::'any? => unit => unit,
      onincomplete : unit => unit,
      oncleared : unit => unit,
      onUnMask : maskedValue::'any => unmaskedValue::'any => unit,
      onBeforeMask : initialValue::'any => unit,
      onKeyValidation : result::'any => unit,
      onBeforePaste : pastedValue::'any => unit
    };
  type maskedInputStatic =
    Js.t {
      ..
      defaults : maskedInputDefaults,
      isValid : value::string => options::maskedInputStaticDefaults => Js.boolean,
      format : value::string => options::maskedInputStaticDefaults => Js.boolean
    };
  type maskedInputStaticDefaults = Js.t {.. alias : string};
  type maskedInputDefaults = Js.t {.. aliases : 'any, definitions : 'any};
  type jQueryStatic = Js.t {.. mask : maskedInputStatic};
  type jQuery =
    Js.t {.. mask : mask::string => options::jQueryMaskedInputOptions? => unit => jQuery};
};
