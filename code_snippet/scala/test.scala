// function
def whileLoop {
    var i = 1
    while (i <= 3){
        println(i)
        i += 1
    }
}

def forLoop {
    println("for loop using Java-stle iteration")
    for (i <- 0 until args.length){
        println(args(i))
    }
}

def rubyStyleForLoop {
    println("for loop using Ruby-style iteration")
    args.foreach { arg =>
        println(arg)
    }
}

class Compass {
    val directions = List("north", "east", "south", "west")
    var bearing = 0
    print("Initial bearing: ")
    println(direction)

    def direction() = directions(bearing)

    def inform(turnDirection: String){
        println("Turning " + turnDirection + ". Now bearing " + direction)
    }

    def turnRight(){
        bearing = (bearing + 1) % directions.size
        inform("right")
    }

    def turnLeft(){
        bearing = (bearing + (directions.size - 1)) % directions.size
        inform("left")
    }
}
val myCompass = new Compass
myCompass.turnRight
myCompass.turnRight
myCompass.turnLeft
myCompass.turnLeft
myCompass.turnLeft

// class
/*
class Person(first_name: String){
    println("Outer constructor")
    def this(first_name: String, last_name: String){
        this(first_name)
        println("Inner constructor")
    }

    def talk() = println("Hi")
}

val bob = new Person("Bob")
val bobTate = new Person("Bob", "Tate")
*/

// object
object TrueRing {
    def rule = println("To rule them all")
}
TrueRing.rule

// hierarchy
/*
class Person(val name: String) {
    def talk(message: String) = println(name + " says " + message)
    def id(): String = name
}

class Employee(override val name: String,
                        val number: Int) extends Person(name) {
    override def talk(message: String) {
        println(name + " with number " + number + " says " + message)
    }
    override def id(): String = number.toString
}

val employee = new Employee("Yoda", 4)
employee.talk("Extend or extend not. There is no try.")
*/

// trait
class Person(val name: String)

trait Nice {
    def greet() = println("Howdily doodily.")
}

class Character(override val name: String) extends Person(name) with Nice

val flanders = new Character("Ned")
flanders.greet

// list, set, map
val list = List("lions", "tigers", "bears")
println(list.isEmpty)
println(list.length)
println(list.size)
println(list.head)
println(list.tail)
println(list.last)
println(list.init)
println(list.reverse)
println(list.drop(1))
println(list.drop(2))
val words = List("peg", "al", "bud", "kelly")
println(words.count(word => word.size > 2))
println(words.filter(word => word.size > 2))
println(words.map(word => word.size))
println(words.forall(word => word.size > 1))
println(words.exists(word => word.size > 4))
val animals = Set("lions", "tigers", "bears")
val ordinals = Map(0 -> "zeor", 1 -> "one", 2 -> "two")

val hobbits_list = List("frodo", "samwise", "pippin")
hobbits_list.foreach(hobbit => println(hobbit))

val hobbits_set = Set("frodo", "samwise", "pippin")
hobbits_set.foreach(hobbit => println(hobbit))

val hobbits_map = Map("frodo" -> "hobbit", "samwise" -> "hobbit", "pippin" -> "hobbit")
hobbits_map.foreach(hobbit => println(hobbit))
hobbits_map.foreach(hobbit => println(hobbit._1))
hobbits_map.foreach(hobbit => println(hobbit._2))