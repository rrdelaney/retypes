module UsersRyanDocumentsDevRetypesDefinitelyTypedTypesBloomfilterIndex = {
  module BloomFilter = {
    type t =
      Js.t {
        .
        buckets : array int32Array,
        add : ('any => unit) [@bs.meth],
        test : ('any => Js.boolean) [@bs.meth]
      };
    external make : float => float => t =
      "BloomFilter"
      [@@bs.new]
      [@@bs.module "/Users/ryan/Documents/dev/retypes/DefinitelyTyped/types/bloomfilter/index"];
  };
};
