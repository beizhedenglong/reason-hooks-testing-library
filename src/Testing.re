module Result = {
  [@bs.deriving abstract]
  type current('value) = {current: 'value};

  [@bs.deriving abstract]
  type t('value) = {result: current('value)};

  [@bs.get] external current: current('value) => 'value = "current";
  [@bs.get] external result: t('value) => current('value) = "result";
};

[@bs.module "react-hooks-testing-library"]
external renderHook: ([@bs.uncurry] (unit => 'hook)) => Result.t('hook) =
  "renderHook";

[@bs.module "react-hooks-testing-library"]
external act: ([@bs.uncurry] (unit => unit)) => unit = "act";