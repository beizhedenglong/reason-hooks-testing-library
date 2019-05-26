module Result = {
  [@bs.deriving {abstract: light}]
  type current('value) = {current: 'value};

  [@bs.deriving {abstract: light}]
  type t('value) = {result: current('value)};
};

[@bs.module "react-hooks-testing-library"]
external renderHook: ([@bs.uncurry] (unit => 'hook)) => Result.t('hook) =
  "renderHook";

[@bs.module "react-hooks-testing-library"]
external act: ([@bs.uncurry] (unit => unit)) => unit = "act";