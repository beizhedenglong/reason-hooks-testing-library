open Jest;
open Expect;
open Testing;

module ContextProvider = {
  let themeContext = React.createContext("light");

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };

  let make = React.Context.provider(themeContext);
};

module App = {
  [@react.component]
  let make = (~children) =>
    <div> <ContextProvider value="dark"> children </ContextProvider> </div>;
};

describe("useContext", () => {
  open Result;

  let options =
    Options.t(
      ~wrapper=App.make,
      ~initialProps=ContextProvider.themeContext,
      (),
    );

  let container =
    renderHook(context => React.useContext(context), ~options, ());
  ();
  test("context value from context provider is 'dark'", () =>
    expect(container->result->current) |> toEqual("dark")
  );
});