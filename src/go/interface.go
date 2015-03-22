package main

import (
    "fmt"
    "math"
)

type Abser interface {
    Abs() float64
}

type MyFloat float64

func (f MyFloat) Abs() float64 {
    if f < 0 {
        return float64(-f)
    }

    return float64(f)
}

type Vertex struct {
    X, Y float64
}

func (v *Vertex) Abs() float64 {
    return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func (v *Vertex) String() string {
    return fmt.Sprintf("call string method, X = %v, Y = %v", v.X, v.Y)
}

func main() {
    var a Abser
    f := MyFloat(-math.Sqrt(2))
    v := Vertex{3, 4}

    a = f
    a = &v

    fmt.Println(a.Abs())
    fmt.Println(&v)
}
