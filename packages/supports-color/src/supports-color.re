type union_of_bool_or_object_or_object_or_object =
  | Bool Js.boolean
  | Object (
      Js.t {.. level : float, hasBasic : Js.boolean, has256 : Js.boolean, has16m : Js.boolean}
    )
  | Object (
      Js.t {.. level : float, hasBasic : Js.boolean, has256 : Js.boolean, has16m : Js.boolean}
    )
  | Object (
      Js.t {.. level : float, hasBasic : Js.boolean, has256 : Js.boolean, has16m : Js.boolean}
    );

type bool_or_object_or_object_or_object;

external bool_or_object_or_object_or_object :
  union_of_bool_or_object_or_object_or_object => bool_or_object_or_object_or_object =
  "Array.prototype.shift.call" [@@bs.val];

external supports_color : bool_or_object_or_object_or_object = "supports-color" [@@bs.module];
