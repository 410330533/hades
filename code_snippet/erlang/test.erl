% This is a comment
List = [1, 2, 3].
Tuple = {comic_strip, {name, "Calvin and Hobbes"}, {character, "Spaceman Spiff"}}.
Person = {person, {name, "Agent Smith"}, {profession, "Killing programs"}}.
{person, {name, Name}, {profession, Profession}} = Person.
[Head | Tail] = [1, 2, 3].
[One, Two | Rest] = [1, 2, 3].

% bit match
W = 1.
X = 2.
Y = 3.
Z = 4.
All = <<W:3, X:3, Y:5, Z:5>>.
<<A:3, B:3, C:5, D:5>> = All.

Animal = "dog".
case Animal of
    "dog" -> underdog;
    "cat" -> thundercat;
    _ -> something_else
end.

if
    x > 0 -> positive;
    x < 0 -> negative;
    true -> zero
end.

Negate = fun(I) -> -I end.
Negate(1).

Numbers = [1, 2, 3, 4].
lists:foreach(fun(Number) -> io:format("~p~n", [Number]) end, Numbers).
lists:map(fun(X) -> X + 1 end, Numbers).