module Result = {
  [@bs.deriving {abstract: light}]
  type current('value) = {current: 'value};

  [@bs.deriving {abstract: light}]
  type t('value) = {result: current('value)};
};

module Options = {
  [@bs.deriving {abstract: light}]
  type t('props) = {
    [@bs.optional]
    initialProps: 'props,
    [@bs.optional]
    wrapper: React.component({. "children": React.element}),
  };
};

[@bs.module "@testing-library/react-hooks"]
external renderHook:
  ([@bs.uncurry] ('props => 'hook), ~options: Options.t('props)=?, unit) =>
  Result.t('hook) =
  "renderHook";

[@bs.module "@testing-library/react-hooks"]
external jsAct: ([@bs.uncurry] (unit => Js.undefined('a))) => unit = "act";

let act = callback =>
  jsAct(() => {
    callback();
    Js.undefined;
  });