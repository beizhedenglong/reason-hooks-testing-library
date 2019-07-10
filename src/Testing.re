module Result = {
  [@bs.deriving {abstract: light}]
  type current('value) = {current: 'value};

  [@bs.deriving {abstract: light}]
  type t('value) = {result: current('value)};
};

module Options = {
  [@bs.deriving {abstract: light}]
  type t = {
    [@bs.optional]
    wrapper: React.component({. "children": React.element}),
  };
};

[@bs.module "@testing-library/react-hooks"]
external renderHook:
  ([@bs.uncurry] (unit => 'hook), ~options: Options.t=?, unit) =>
  Result.t('hook) =
  "renderHook";

[@bs.module "@testing-library/react-hooks"]
external act: ([@bs.uncurry] (unit => unit)) => unit = "act";
