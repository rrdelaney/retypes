type callback 't = item::'t => unit;

type comparator 't = a::'t => b::'t => float;

module Iterator = {
  type t 't =
    Js.t {
      .
      data : (unit => 't) [@bs.meth],
      next : (unit => 't) [@bs.meth],
      prev : (unit => 't) [@bs.meth]
    };
  external make : TreeBase.t t => t = "Iterator" [@@bs.new] [@@bs.module "bintrees"];
};

module TreeBase = {
  type t 't =
    Js.t {
      .
      size : float,
      clear : (unit => unit) [@bs.meth],
      find : ('t => 't) [@bs.meth],
      findIter : ('t => Iterator.t 't) [@bs.meth],
      lowerBound : ('t => Iterator.t 't) [@bs.meth],
      upperBound : ('t => Iterator.t 't) [@bs.meth],
      min : (unit => 't) [@bs.meth],
      max : (unit => 't) [@bs.meth],
      iterator : (unit => Iterator.t 't) [@bs.meth],
      each : (callback 't => unit) [@bs.meth],
      reach : (callback 't => unit) [@bs.meth]
    };
  external make : _::unit => t = "TreeBase" [@@bs.new] [@@bs.module "bintrees"];
};

module RBTree = {
  type t 't =
    Js.t {. insert : ('t => Js.boolean) [@bs.meth], remove : ('t => Js.boolean) [@bs.meth]};
  external make : comparator t => t = "RBTree" [@@bs.new] [@@bs.module "bintrees"];
};

module BinTree = {
  type t 't =
    Js.t {. insert : ('t => Js.boolean) [@bs.meth], remove : ('t => Js.boolean) [@bs.meth]};
  external make : comparator t => t = "BinTree" [@@bs.new] [@@bs.module "bintrees"];
};
