package main

import (
    "fmt"
    "math"
    "math/cmplx"
    "runtime"
    "time"
)

var c, python, java bool
var i, j int = 1, 2
var (
    ToBe    bool        = false
    MaxInt  uint64      = 1<<64 - 1
    z       complex128  = cmplx.Sqrt(-5 + 12i)
)

type Vertex struct {
    X int
    Y int
}

type Coordinate struct {
    Lat float64
    Long float64
}

func add(x int, y int) int {
    return x + y
}

func swap(x, y string) (string, string) {
    return y, x
}

func split(sum int) (x, y int) {
    x = sum * 4 / 9
    y = sum - x
    return
}

func sqrt(x float64) string {
    if x < 0 {
        return sqrt(-x) + "i"
    }
    return fmt.Sprint(math.Sqrt(x))
}

func pow(x, n, lim float64) float64 {
    if v := math.Pow(x, n); v < lim {
        return v
    } else {
        fmt.Printf("%g >= %g\n", v, lim)
    }
    return lim
}

func adder() func(int) int {
    sum := 0
    return func(x int) int {
        sum += x
        return sum
    }
}

func main() {
    // defer
    defer fmt.Println("defer func should at last")
    for i:=0; i<5; i++ {
        defer fmt.Println(i)
    }

    a, b := "hello", "world"
    fmt.Println(a, b)

    a, b = swap(a, b)
    fmt.Println(a, b)

    fmt.Println(split(17))

    var c, python, java = true, false, "no!"
    fmt.Println(i, j, c, python, java)

    const f = "%T(%v)\n"
    fmt.Printf(f, ToBe, ToBe)
    fmt.Printf(f, MaxInt, MaxInt)
    fmt.Printf(f, z, z)

    // for
    sum := 0
    for i:=0; i<101; i++ {
        sum += i
    }
    fmt.Println(sum)

    // for continued
    sum = 1
    for ; sum < 1000; {
        sum += sum
    }
    fmt.Println(sum)

    // while style
    sum = 1
    for sum < 1000 {
        sum += sum
    }
    fmt.Println(sum)

    fmt.Println(sqrt(2), sqrt(-4))
    fmt.Println(pow(3, 2, 10), pow(3, 3, 20))
    
    // switch
    switch os := runtime.GOOS; os {
        case "darwin":
            fmt.Println("OS X")
        case "linux":
            fmt.Println("Linux")
        default:
            fmt.Println("%s", os)
    }

    t := time.Now()
    switch {
        case t.Hour() < 12:
            fmt.Println("Good morning!")
        case t.Hour() < 17:
            fmt.Println("Good afternoon.")
        default:
            fmt.Println("Good evening.")
    }

    // pointer
    i, j := 42, 2701
    p := &i
    fmt.Println(*p)
    *p = 21
    fmt.Println(i)
    p = &j
    *p = *p / 37
    fmt.Println(j)

    // struct
    v := Vertex{1, 2}
    vp := &v
    vp.X = 1e9
    fmt.Println(v)
    v2 := Vertex{X: 3}
    fmt.Println(v2)

    // array
    var strArray [2]string
    strArray[0] = "Hello"
    strArray[1] = "World"
    fmt.Println(strArray)

    // slice
    slice := []int{2, 3, 5, 7, 11, 13}
    fmt.Println("slice len = ", len(slice))
    fmt.Println(slice)
    fmt.Println("slice[1:4] ==", slice[1:4])
    fmt.Println("slice[:3] ==", slice[:3])
    fmt.Println("slice[4:] ==", slice[4:])
    sa := make([]int, 5)
    fmt.Printf("len = %d, cap = %d, %v\n", len(sa), cap(sa), sa)
    sb := make([]int, 0, 5)
    fmt.Printf("len = %d, cap = %d, %v\n", len(sb), cap(sb), sb)
    sc := sb[:2]
    fmt.Printf("len = %d, cap = %d, %v\n", len(sc), cap(sc), sc)
    sd := sc[2:5]
    fmt.Printf("len = %d, cap = %d, %v\n", len(sd), cap(sd), sd)
    // Adding elements to a slice
    var se []int
    fmt.Printf("len = %d, cap = %d, %v\n", len(se), cap(se), se)
    se = append(se, 0)
    fmt.Printf("len = %d, cap = %d, %v\n", len(se), cap(se), se)
    se = append(se, 1)
    fmt.Printf("len = %d, cap = %d, %v\n", len(se), cap(se), se)
    se = append(se, 2, 3, 4)
    fmt.Printf("len = %d, cap = %d, %v\n", len(se), cap(se), se)

    // Range
    var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}
    for i, v := range pow {
        fmt.Printf("2**%d = %d\n", i, v)
    }

    // map
    var m map[string]Coordinate
    m = make(map[string]Coordinate)
    m["Bell Labs"] = Coordinate {40.68433, -74.39967}
    fmt.Println(m["Bell Labs"])
    var ms = map[string]Coordinate {
        "Bell Labs": Coordinate {
            40.68433, -74.39967,
        },
        "Google": Coordinate {
            37.42202, -122.08408,
        },
    }
    fmt.Println(ms)
    // mutating maps
    // m[key] = elem
    // elem = m[key]
    // delete(m, key)
    // elem, ok = m[key]
    
    // Function values
    hypot := func(x, y float64) float64 {
        return math.Sqrt(x*x + y*y)
    }
    fmt.Println("hypot call = ", hypot(3, 4))

    // Function closures
    pos, neg := adder(), adder()
    for i:=0; i<5; i++ {
        fmt.Println(pos(i), neg(-2*i))
    }
}
