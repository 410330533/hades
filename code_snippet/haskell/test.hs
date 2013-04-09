module Main where
    double :: Integer -> Integer
    double x = x + x
-- :load test.hs
-- double 5

let fact x = if x == 0 then 1 else fact (x - 1) * x

-- factorial.hs
    factorial :: Integer -> Integer
    factorial 0 = 1
    factorial x = x * factorial (x - 1)

-- factorial_with_guard.hs
    factorial_with_guard :: Integer -> Integer
    factorial_with_guard x
        | x > 1 = x * factorial_with_guard (x - 1)
        | otherwise = 1

-- fib.hs
    fib :: Integer -> Integer
    fib 0 = 1
    fib 1 = 1
    fib x = fib(x - 1) + fib(x - 2)

4 + 4
4 + 1.0
"hello" ++ " world"
(4 + 5) == 9
(5 + 5) /= 10
