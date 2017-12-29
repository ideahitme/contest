package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(1<<63 - 1)
	fmt.Println(math.MaxInt64)
	fmt.Println(-1 << 63)
	fmt.Println(math.MinInt64)
}
