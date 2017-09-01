package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	x := make([]int, n)
	r := make([]int, n+1)
	for i := 0; i < n; i++ {
		scanner.Scan()
		x[i], _ = strconv.Atoi(scanner.Text())
	}

	r[n] = 1e6
	for i := n - 1; i > -1; i-- {
		if x[i] == 0 {
			r[i] = 0
			continue
		}
		r[i] = r[i+1] + 1
	}

	l := int(1e6)
	for i := 0; i < n; i++ {
		l++
		if x[i] == 0 {
			l = 0
		}
		fmt.Printf("%d ", min(r[i], l))
	}
	fmt.Println()
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
