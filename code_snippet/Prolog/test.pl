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