package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

const (
	max = math.MaxInt32
	min = math.MinInt32
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())
	for i := 1; i <= t; i++ {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		k, _ := strconv.Atoi(scanner.Text())
		a := make([]int, n)
		for j := 0; j < n; j++ {
			scanner.Scan()
			a[j], _ = strconv.Atoi(scanner.Text())
		}
		sort.Sort(sort.Reverse(sort.IntSlice(a)))
		var answer int64
		for a[k-1] > 0 {
			answer += int64(a[k-1])
			for l := 0; l < k; l++ {
				a[l] -= a[k-1]
			}
			a = merge(a, k)
		}
		fmt.Printf("Case %d: %d\n", i, answer)
	}
}

func merge(a []int, k int) []int {
	res := make([]int, len(a))
	x := 0
	y := k
	i := 0
	for x < k && y < len(a) {
		if a[x] > a[y] {
			res[i] = a[x]
			x++
		} else {
			res[i] = a[y]
			y++
		}
		i++
	}
	for x < k {
		res[i] = a[x]
		x++
		i++
	}
	for y < len(a) {
		res[i] = a[y]
		y++
		i++
	}
	return res
}
