package main

import (
	"fmt"
)

func max(x, y int) int {
	if x >= y {
		return x
	}
	return y
}

func main() {
	var x string
	fmt.Scanln(&x)
	ans := 0
	alp := make([]int, 200)
	c := make([]int, len(x))
	for i := 0; i < len(x); i++ {
		c[i] = int(x[i])
	}
	l := 0
	r := 0
	for r < len(x) {
		alp[c[r]]++
		for l <= r {
			no_dupl := true
			for i := range alp {
				no_dupl = no_dupl && (alp[i] < 2)
			}
			if no_dupl {
				break
			}
			alp[c[l]]--
			l++
		}
		ans = max(ans, r-l+1)
		r++
	}
	fmt.Println(ans)
}
