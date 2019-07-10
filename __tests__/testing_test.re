open Jest;
open Expect;
open Testing;

type counterType = {
  counter: int,
  set: (int => int) => unit,
};
let useCounter = initial => {
  let (counter, set) = React.useState(() => initial);
  {counter, set};
};

describe("useCounter", () => {
  open Result;
  let container = renderHook(() => useCounter(0), ());
  test("counter is 0", () =>
    expect(container->result->current.counter) |> toEqual(0)
  );
  test("counter is 1", () => {
    act(() => container->result->current.set(prev => prev + 1));
    expect(container->result->current.counter) |> toEqual(1);
  });
  test("counter is 2", () => {
    act(() => container->result->current.set(prev => prev + 1));
    expect(container->result->current.counter) |> toEqual(2);
  });
});