# basic
i := 1
while(i <= 11, i println; i = i + 1); "This one goes up to 11" println
for(i, 1, 11, 2, i println); "This one goes up to 11" println
if(true, "It is true." println, "It is false." println)
if(false) then("It is true" println) else("It is false" println)

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

# operator
OperatorTable addOperator("xor", 11)
true xor := method(bool, if(bool, false, true))
false xor := method(bool, if(bool, true, false))

# message
postOffice := Object clone
postOffice packageSender := method(call sender)

mailer := Object clone
mailer deliver := method(postOffice packageSender)

postOffice messageTarget := method(call target)
postOffice messageArgs := method(call message arguments)
postOffice messageName := method(call message name)

# DSL(domain specific language)
/*
{
    "Bob Smith": "5195551212",
    "Mary Walsh": "4162223434"
}
*/
OperatorTable addAssignOperator(":", "atPutNumber")
curlyBrackets := method(
    r := Map clone
    call message arguments foreach(arg,
        r doMessage(arg)
        )
    r
)
Map atPutNumber := method(
    self atPut(
        call evalArgAt(0) asMutable removePrefix("\"") removeSuffix("\""),
        call evalArgAt(1))
)
s := File with("phonebook.txt") openForReading contents
phoneNumbers := doString(s)
phoneNumbers keys println
phoneNumbers values println

# forward
Builder := Object clone
Builder forward := method(
    writeln("<", call message name, ">")
    call message arguments foreach(
        arg,
        content := self doMessage(arg);
        if(content type == "Sequence", writeln(content))
    )
    writeln("</", call message name, ">")
)

Builder ul(
    li("Io"), li("Lua"), li("Javascript")
)

# coroutine
vizzini := Object clone
vizzini talk := method(
    "fezzik, are there rocks ahead?" println
    yield
    "no more rhymes now, I mean it." println
    yield
)

fezzik := Object clone
fezzik rhyme := method(
    yield
    "If there are, we'll all be dead." println
    yield
    "Anybody want a peanut?" println
)

vizzini @@talk; fezzik @@rhyme
# Coroutine currentCoroutine pause

# actor
slower := Object clone
faster := Object clone
slower start := method(wait(2); writeln("slowly"))
faster start := method(wait(1); writeln("quickly"))
slower start; faster start
slower @@start; faster @@start; wait(3)

# future
/*
futureResult := URL with("http://google.com/") @fetch
writeln("我们可以在后台运行网页抓取的同时做一些别的事情。。。")
writeln("这里将阻塞，直到结果产生为止")
writeln("fetch ", futureResult size, " bytes")
*/