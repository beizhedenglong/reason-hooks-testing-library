// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReactHooks = require("@testing-library/react-hooks");
var Testing$ReasonHooksTestingLibrary = require("../src/Testing.bs.js");

function useCounter(initial) {
  var match = React.useState((function () {
          return initial;
        }));
  return /* record */[
          /* counter */match[0],
          /* set */match[1]
        ];
}

Jest.describe("useCounter", (function (param) {
        var container = ReactHooks.renderHook((function (param) {
                return useCounter(0);
              }), undefined);
        Jest.test("counter is 0", (function (param) {
                return Jest.Expect[/* toEqual */12](0, Jest.Expect[/* expect */0](container.result.current[/* counter */0]));
              }));
        Jest.test("counter is 1", (function (param) {
                Testing$ReasonHooksTestingLibrary.act((function (param) {
                        return Curry._1(container.result.current[/* set */1], (function (prev) {
                                      return prev + 1 | 0;
                                    }));
                      }));
                return Jest.Expect[/* toEqual */12](1, Jest.Expect[/* expect */0](container.result.current[/* counter */0]));
              }));
        return Jest.test("counter is 2", (function (param) {
                      Testing$ReasonHooksTestingLibrary.act((function (param) {
                              return Curry._1(container.result.current[/* set */1], (function (prev) {
                                            return prev + 1 | 0;
                                          }));
                            }));
                      return Jest.Expect[/* toEqual */12](2, Jest.Expect[/* expect */0](container.result.current[/* counter */0]));
                    }));
      }));

exports.useCounter = useCounter;
/*  Not a pure module */
