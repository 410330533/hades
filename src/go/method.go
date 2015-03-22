package main

import (
    "fmt"
    "math"
)

type Vertex struct {
    X, Y float64
}

// There are two reasons to use a pointer receiver.
// First, to avoid copying the value on each method call (more efficient if the value type is a large struct).
// Second, so that the method can modify the value that its receiver points to.
func (v *Vertex) Abs() float64 {
    return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func (v *Vertex) Scale(f float64) {
    v.X = v.X * f
    v.Y = v.Y * f
}

func main() {
    v := &Vertex{3, 4}
    fmt.Println(v.Abs())

    fmt.Println(v)
    v.Scale(5)
    fmt.Println(v)
}
