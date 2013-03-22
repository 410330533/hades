-module(function).
-export([mirror/1]).
-export([number/1]).
-export([another_factorial/1]).
-export([another_fib/1]).
-export([double_all/1]).

mirror(Anything) -> Anything.

number(one) -> 1;
number(two) -> 2;
number(three) -> 3.

another_factorial(0) -> 1;
another_factorial(N) -> N * another_factorial(N - 1).

another_fib(0) -> 1;
another_fib(1) -> 1;
another_fib(N) -> another_fib(N-1) + another_fib(N-2).

double_all([]) -> [];
double_all([First|Rest]) -> [First + First|double_all(Rest)].