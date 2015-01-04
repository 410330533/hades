package main

import (
    "fmt"
    "math"
    "math/cmplx"
)

var c, python, java bool
var i, j int = 1, 2
var (
    ToBe    bool        = false
    MaxInt  uint64      = 1<<64 - 1
    z       complex128  = cmplx.Sqrt(-5 + 12i)
)

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

func main() {
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
}
