module Main where
    double :: Integer -> Integer
    double x = x + x
-- :load test.hs
-- double 5

let fact x = if x == 0 then 1 else fact (x - 1) * x

------------------------------
-- factorial.hs
    factorial :: Integer -> Integer
    factorial 0 = 1
    factorial x = x * factorial (x - 1)

------------------------------
-- factorial_with_guard.hs
    factorial_with_guard :: Integer -> Integer
    factorial_with_guard x
        | x > 1 = x * factorial_with_guard (x - 1)
        | otherwise = 1

------------------------------
-- fib.hs
    fib :: Integer -> Integer
    fib 0 = 1
    fib 1 = 1
    fib x = fib(x - 1) + fib(x - 2)

------------------------------    
    fibTuple :: (Integer, Integer, Integer) -> (Integer, Integer, Integer)
    fibTuple (x, y, 0) = (x, y, 0)
    fibTuple (x, y, index) = fibTuple (y, x + y, index - 1)
-- :load fibTuple.hs
-- fibTuple(0, 1, 4)

------------------------------
    fibTuple :: (Integer, Integer, Integer) -> (Integer, Integer, Integer)
    fibTuple (x, y, 0) = (x, y, 0)
    fibTuple (x, y, index) = fibTuple (y, x + y, index - 1)
    
    fibResult :: (Integer, Integer, Integer) -> Integer
    fibResult (x, y, z) = x
    
    fib :: Integer -> Integer
    fib x = fibResult (fibTuple (0, 1, x))

------------------------------
    fibNextPair :: (Integer, Integer) -> (Integer, Integer)
    fibNextPair (x, y) = (y, x + y)
    
    fibNthPair :: Integer -> (Integer, Integer)
    fibNthPair 1 = (1, 1)
    fibNthPair n = fibNextPair (fibNthPair (n - 1))
    
    fib :: Integer -> Integer
    fib = fst . fibNthPair

-- list
    size [] = 0
    size (h:t) = 1 + size t
    
    prod [] = 1
    prod (h:t) = h * prod t
-- :load lists.hs
-- size "Fascinating."

4 + 4
4 + 1.0
"hello" ++ " world"
(4 + 5) == 9
(5 + 5) /= 10
