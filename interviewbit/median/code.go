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

	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}

	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	b := make([]int, m)
	for i := 0; i < m; i++ {
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
	}

	fmt.Println(median(a, b, 3))
	fmt.Println(median(b, a, 3))
}

func median(a, b []int, i int) (int, bool) {
	l := 0
	r := len(a) - 1

	for l < r {
		med := (l + r) / 2

		t := val(a, b, med, i-med)
		if t == 0 {
			return med, true
		}
		if t == -1 {
			l = med + 1
		}
		if t == 1 {
			r = med
		}
	}

	return l, false
}

func val(a, b []int, x, y int) int {
	if y < 0 {
		return 1
	}
	if len(b) <= y {
		return -1
	}
	if a[x] > b[y] {
		return 1
	}
	if y-1 >= 0 && a[x] < b[y-1] {
		return -1
	}
	return 0
}
