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

    allEven :: [Integer] -> [Integer]
    allEven [] = []
    allEven (h:t) = if even h then h:allEven t else allEven t

-- list
[1..4]
[10, 8 .. 4]
[10, 9.5 .. 4]
take 5 [1 ..]
[x * 2 | x <- [1, 2, 3]]
[(y, x) | (x, y) <- [(1, 2), (2, 3), (3, 1)]]
[(4 - x, y) | (x, y) <- [(1, 2), (2, 3), (3, 1)]]

-- anonymous function
(\x -> x) "Logical."
(\x -> x ++ " caption.") "Logical, "

-- map
map(\x -> x * x) [1, 2, 3]
map(+ 1) [1, 2, 3]

-- filter
filter odd [1, 2, 3, 4, 5]

-- 偏应用函数 柯里化
let prod x y = x * y
let double = prod 2
let triple = prod 3

-- 惰性求值
module Main where
    myRange start step = start:(myRange (start + step) step)
module Main where
    lazyFib x y = x:(lazyFib y (x + y))
    fib = lazyFib 1 1
    fibNth x = head (drop (x - 1) (take (x) fib))
-- take 5 (lazyFib 0 1)
-- take 5 (fib)
-- take 5 (drop 20 (lazyFib 0 1))
-- fibNth 3
-- fibNth 6
-- take 5 (zipWith (+) fib (drop 1 fib))
-- take 5 (map (*2) [1 ..])
-- take 5 (map ((* 2) . (* 5)) fib)

-- 类型
module Main where
    data Suit = Spaces | Hearts deriving (Show)
    data Rank = Ten | Jack | Queen | King | Ace deriving (Show)
    type Card = (Rank, Suit)
    type Hand = [Card]

let crew = ["Kirk", "Spock", "McCoy"]
[(a, b) | a <- crew, b <- crew]
[(a, b) | a <- crew, b <- crew, a /= b]
[(a, b) | a <- crew, b <- crew, a < b]

4 + 4
4 + 1.0
"hello" ++ " world"
(4 + 5) == 9
(5 + 5) /= 10
