package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var res []int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	solve(n, k)
	if len(res) == 0 || len(res) != k {
		fmt.Println(-1)
		os.Exit(0)
	}
	check := 1
	for _, el := range res {
		check *= el
	}
	if check != n {
		fmt.Println(-1)
		os.Exit(0)
	}
	for i, el := range res {
		if i == len(res)-1 {
			fmt.Printf("%d\n", el)
			continue
		}
		fmt.Printf("%d ", el)
	}
}

func solve(n, k int) {
	if n == 1 {
		return
	}
	if k == 1 {
		res = append(res, n)
		return
	}
	for i := 2; i <= int(math.Sqrt(float64(n)))+1; i++ {
		if n%i == 0 {
			res = append(res, i)
			solve(n/i, k-1)
			return
		}
	}
}
