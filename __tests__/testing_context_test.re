open Jest;
open Expect;
open Testing;

module type Config = {
  type context;
  let defaultValue: context;
};

module Context = (Config: Config) => {
  let context = React.createContext(Config.defaultValue);
  module Provider = {
    let make = context->React.Context.provider;
    [@bs.obj]
    external makeProps:
      (
        ~value: Config.context,
        ~children: React.element,
        ~key: string=?,
        unit
      ) =>
      {
        .
        "value": Config.context,
        "children": React.element,
      } =
      "";
  };
};

module TestContext = {
  type t = string;

  include Context({
    type context = t;
    let defaultValue = "foo";
  });
};

module Provider = {
  [@react.component]
  let make = (~children) =>
    <TestContext.Provider value="bar"> children </TestContext.Provider>;
};

describe("useContext", () => {
  open Result;

  let options = Options.t(~wrapper=Provider.make, ());

  let container =
    renderHook(() => React.useContext(TestContext.context), ~options, ());

  test("context value from context provider is 'bar'", () =>
    expect(container->result->current) |> toEqual("bar")
  );
});
