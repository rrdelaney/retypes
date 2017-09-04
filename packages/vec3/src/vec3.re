module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesVec3Index = {
  module Vec3 = {
    type t =
      Js.t {
        .
        set : (float => float => float => Vec3.t) [@bs.meth],
        update : (Vec3.t => Vec3.t) [@bs.meth],
        floored : (unit => Vec3.t) [@bs.meth],
        floor : (unit => Vec3.t) [@bs.meth],
        offset : (float => float => float => Vec3.t) [@bs.meth],
        translate : (float => float => float => Vec3.t) [@bs.meth],
        add : (Vec3.t => Vec3.t) [@bs.meth],
        substract : (Vec3.t => Vec3.t) [@bs.meth],
        plus : (Vec3.t => Vec3.t) [@bs.meth],
        minus : (Vec3.t => Vec3.t) [@bs.meth],
        scaled : (float => Vec3.t) [@bs.meth],
        abs : (unit => Vec3.t) [@bs.meth],
        volume : (unit => float) [@bs.meth],
        modulus : (unit => Vec3.t) [@bs.meth],
        distanceTo : (Vec3.t => float) [@bs.meth],
        equals : (Vec3.t => Js.boolean) [@bs.meth],
        toString : (unit => string) [@bs.meth],
        clone : (unit => Vec3.t) [@bs.meth],
        min : (Vec3.t => Vec3.t) [@bs.meth],
        max : (Vec3.t => Vec3.t) [@bs.meth]
      };
    external make : float => float => float => t =
      "Vec3"
      [@@bs.new]
      [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/vec3/index"];
  };
};
