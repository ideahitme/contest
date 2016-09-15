package main

import (
	"fmt"
	"sort"
)

/**
 * x is the target element
 * a is a sorted slice
 */
func b_search(x int, a []int, l, r int) int {
	var mid int
	for l < r {
		mid = (l + r) / 2
		if a[mid] < x {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}

func main() {
	var size int
	fmt.Scanln(&size)
	a := make([]int, size)
	for i := 0; i < size; i++ {
		fmt.Scanf("%d", &a[i])
	}
	res := make([][]int, 0)
	sort.Ints(a)
	n := len(a)
	for i := 0; i < n-2; i++ {
		if i > 0 && a[i] == a[i-1] {
			continue
		}
		for j := i + 1; j < n-1; j++ {
			if a[j] == a[j-1] && j-1 != i {
				continue
			}
			x := -(a[i] + a[j])
			t := b_search(x, a, j+1, n-1)
			if t < n && a[t] == x {
				res = append(res, []int{a[i], a[j], a[t]})
			}
		}
	}
	fmt.Println(res)
}
