package main

import "fmt"

type longlong int64

const (
	MIN = longlong(-1e12)
)

func main() {
	var t int
	fmt.Scan(&t)
	for q := 0; q < t; q++ {
		var n int
		fmt.Scan(&n)
		d := make([]longlong, n, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&d[i])
		}
		r := make([]longlong, n+1, n+1)
		r[0] = 0
		for i := 1; i < n+1; i++ {
			r[i] = MIN
		}
		x := make([]longlong, n, n)
		for i := 0; i < n; i++ {
			rank := d[i]
			if r[rank] == MIN {
				r[rank] = r[rank-1] + longlong(n+1)
			} else {
				r[rank]--
			}
			x[i] = r[rank]
		}
		for i := 0; i < n; i++ {
			fmt.Printf("%d ", x[i])
		}
		fmt.Print("\n")
	}
}
