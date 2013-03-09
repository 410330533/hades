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
