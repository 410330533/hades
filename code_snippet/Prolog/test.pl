# friends.pl
likes(wallace, cheese).
likes(grommit, cheese).
likes(wendolene, sheep).

friend(X, Y) :- \+(X = Y), likes(X, Z), likes(Y, Z).

# complie
# gprolog
# | ?- ['friends.pl'].
# | ?- likes(wallace, sheep).
# | ?- likes(grommit, cheese).
# | ?- friend(wallace, wallace).
# | ?- friend(grommit, wallace).
# | ?- friend(wendolene, grommit).

# food.pl
food_type(velveeta, cheese).
food_type(ritz, cracker).
food_type(spam, meat).
food_type(sausage, meat).
food_type(jolt, soda).
food_type(twinkie, dessert).

flavor(sweet, dessert).
flavor(savory, meat).
flavor(savory, cheese).
flavor(sweet, soda).

food_flavor(X, Y) :- food_type(X, Z), flavor(Y, Z).

# complie
# | ?- ['food.pl'].
# | ?- food_type(what, meat).
# | ?- food_flavor(sausage, sweet).
# | ?- flavor(sweet, what).
# | ?- food_flavor(what, savory).

# map.pl
different(red, green). different(red, blue).
different(green, red). different(green, blue).
different(blue, red). different(blue, green).

coloring(Alabama, Mississippi, Georgia, Tennessee, Florida) :-
    different(Mississippi, Tennessee),
    different(Mississippi, Alabama),
    different(Alabama, Tennessee),
    different(Alabama, Mississippi),
    different(Alabama, Georgia),
    different(Alabama, Florida),
    different(Georgia, Florida),
    different(Georgia, Tennessee).

# complie
# | ?- coloring(Alabama, Mississippi, Georgia, Tennessee, Florida).

# ohmy.pl
cat(lion).
cat(tiger).

dorothy(X, Y, Z) :- X = lion, Y = tiger, Z = bear.
twin_cats(X, Y) :- cat(X), cat(Y).

# complie
# | ?- ['ohmy.pl'].
# | ?- dorothy(lion, tiger, bear).
# | ?- dorothy(One, Two, Three).
# | ?- twin_cats(One, Two).

# family.pl
father(zeb, john_boy_sr).
father(john_boy_sr, john_boy_jr).

ancestor(X, Y) :- father(X, Y).
ancestor(X, Y) :- father(X, Z), ancestor(Z, Y).

# complie
# | ?- ancestor(john_boy_sr, john_boy_jr).
# | ?- ancestor(zeb, john_boy_jr).
# | ?- ancestor(zeb, who).
# | ?- ancestor(who, john_boy_jr).

# unification
| ?- (1, 2, 3) = (1, 2, 3).
| ?- (1, 2, 3) = (1, 2, 3, 4).
| ?- (1, 2, 3) = (3, 2, 1).
| ?- (A, B, C) = (1, 2, 3).
| ?- (1, 2, 3) = (A, B, C).
| ?- (A, 2, C) = (1, B, 3).
| ?- [1, 2, 3] = [1, 2, 3].
| ?- [1, 2, 3] = [X, Y, Z].
| ?- [2, 2, 3] = [X, X, Z].
| ?- [1, 2, 3] = [X, X, Z].
| ?- [] = [].

| ?- [a, b, c] = [Head|Tail].
| ?- [] = [Head|Tail].
| ?- [a] = [Head|Tail].
| ?- [a, b, c] = [a|Tail].
| ?- [a, b, c] = [a|[Head|Tail]].
| ?- [a, b, c, d, e] = [_, _|[Head|_]].

# list_math.pl
count(0, []).
count(Count, [Head|Tail]) :- count(TainCount, Tail), Count is TainCount + 1.

sum(0, []).
sum(Total, [Head|Tail]) :- sum(Sum, Tail), Total is Head + Sum.

average(Average, List) :- sum(Sum, List), count(Count, List), Average is Sum/Count.

# complie
# | ?- count(what, [1]).
# | ?- sum(what, [1, 2, 3]).
# | ?- average(what, [1, 2, 3]).

# sudoku.pl
valid([]).
valid([Head|Tail]) :-
    fd_all_different(Head),
    valid(Tail).
    
sudoku(Puzzle, Solution) :-
    Solution = Puzzle,
    Puzzle = [S11, S12, S13, S14,
              S21, S22, S23, S24,
              S31, S32, S33, S34,
              S41, S42, S43, S44],
    
    fd_domain(Solution, 1, 4),
    
    Row1 = [S11, S12, S13, S14],
    Row2 = [S21, S22, S23, S24],
    Row3 = [S31, S32, S33, S34],
    Row4 = [S41, S42, S43, S44],
    
    Col1 = [S11, S21, S31, S41],
    Col2 = [S12, S22, S32, S42],
    Col3 = [S13, S23, S33, S43],
    Col4 = [S14, S24, S34, S44],
    
    Square1 = [S11, S12, S21, S22],
    Square2 = [S13, S14, S23, S24],
    Square3 = [S31, S32, S41, S42],
    Square4 = [S33, S34, S43, S44],
    
    valid([Row1, Row2, Row3, Row4,
           Col1, Col2, Col3, Col4,
           Square1, Square2, Square3, Square4]).

# complie
# | ?- sudoku([_, _, 2, 3,
             # _, _, _, _,
             # _, _, _, _,
             # 3, 4, _, _],
             # Solution).