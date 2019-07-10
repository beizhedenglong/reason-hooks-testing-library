# reason-hooks-testing-library

Reason bindings for [`react-hooks-testing-library`](https://github.com/mpeyper/react-hooks-testing-library).

## Installation
`npm install --save-dev reason-hooks-testing-library`

Then add `reason-hooks-testing-library` to `bs-dev-dependencies` in your `bsconfig.json`:

```json
{
  "bs-dev-dependencies": ["@glennsl/bs-jest", "reason-hooks-testing-library"]
}
```

## Example

```reason

open Jest;
open Expect;
open ReasonHooksTestingLibrary.Testing;

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

```
[More examples](https://github.com/beizhedenglong/reason-hooks-testing-library/tree/master/__tests__)

