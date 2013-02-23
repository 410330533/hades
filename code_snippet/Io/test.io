"Hi ho, Io" println

# object
Vehicle := Object clone
Vehicle description := "Something to take you places"
Vehicle description = "Something to take you far away"

Car := Vehicle clone
ferrari := Car clone

Car drive := method("Vroom" println)
ferrari drive

# method
fib := method(n,
    if (n < 2,
        1,
        fib(n-1) + fib(n-2)
    )
)

# prototype
Person := Object clone do(
    name := nil
    age := 1
    sayhi := method(
        "hi" println
    )
)
me := Person clone do(
    name := "jacky"
    age := 0
)

# list
toDos := list("find my car", "find Continum Transfunctioner")
toDos append("Find a present")

numbers := list(1, 2, 3, 4)
result := numbers average
result := numbers sum
result := numbers at(1)
result := numbers append(5)
result := numbers pop
result := numbers prepend(-1)
result := numbers isEmpty

# map
elvis := Map clone
result := elvis atPut("home", "Graceland")
result := elvis at("home")
result := elvis atPut("style", "rock and roll")
result := elvis asObject
result := elvis asList
result := elvis keys
result := elvis size

# singleton
Highlander := Object clone
Highlander clone := Highlander
