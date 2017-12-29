package main

import (
	"bufio"
	"fmt"
	"os"
)

var ten [251]map[int64]int64
var diffcount [251]map[int64]int64
var tenans [251]int64
var all [251]map[int64]int64

const N = 1e9 + 7

var total []int64

type occ struct {
	val   int64
	times int64
}

func main() {
	for i := 0; i < 251; i++ {
		ten[i] = map[int64]int64{}
	}
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	// idea
	// ctx[5][-3] - will store the number of pairs of x, y < 1e5, such that S[x] - S[y] = -3
	// then we can recursively reduce for the given n, by considering the following cases:
	// if n = x1x2..xk <- base 10 representation:
	// four cases:
	// x and y both have k digits, then we go through all cases of first digit (1, 9), (2, 9), .. (9, 1) and get the result by ctx[4][1-9] etc
	// if x has less than k digits, then we can add ...
	// if y has less than k digits, similarly ...
	// if both has less than k digits, this was already calculated

	scanner.Scan()
	n := scanner.Text()

	for i := 0; i < len(n)+1; i++ {
		ten[i] = map[int64]int64{}
		if i == 0 {
			ten[i][0] = 1
			continue
		}
		for k, v := range ten[i-1] {
			for j := int64(0); j <= 9; j++ {
				if _, ok := ten[i][k+j]; !ok {
					ten[i][k+j] = 0
				}
				ten[i][k+j] += v % N
				ten[i][k+j] %= N
			}
		}
	}

	for i := 0; i < len(n)+1; i++ {
		diffcount[i] = map[int64]int64{}
		if i == 0 {
			diffcount[i] = map[int64]int64{0: 1}
			continue
		}
		if i == 1 {
			for r := int64(0); r <= 9; r++ {
				for l := int64(0); l <= 9; l++ {
					diffcount[i][r-l] += 1
				}
			}
			continue
		}
		for a, b := range diffcount[1] {
			for k, v := range diffcount[i-1] {
				diffcount[i][k+a] += b * v
				diffcount[i][k+a] %= N
			}
		}
	}

	for i := 0; i < len(n)+1; i++ {
		if i == 0 {
			tenans[i] = 0
			continue
		}
		if i == 1 {
			tenans[1] = 45
			continue
		}
		for r := 0; r <= 9; r++ {
			for l := 0; l <= r; l++ {
				// r is the first digit of y, and l is the first digit of l
				if r == l {
					// we take the count of the 10e
					tenans[i] += tenans[i-1]
					tenans[i] %= N
				} else {
					//				y is automatically greater than x
					diff := int64(r - l)
					for k, v := range diffcount[i-1] {
						if diff+k > 0 {
							tenans[i] += int64(v)
							tenans[i] %= N
						}
					}
				}
			}
		}
	}
	total = make([]int64, len(n))
	calc(n)

	fmt.Printf("%d\n", total[len(total)-1])
}


func calc(n string) {
	for i := len(n) - 1 ; i >= 0; i-- {
		index := len(n) - 1 - i
		all[index] = map[int64]int64{}

		if index == 0 {
			for j := int64(0); j <= int64(n[i]-'0'); j++ {
				all[index][j] = 1
			}
			total[index] = int64(n[i]-'0') * int64(n[i]-'0'+1)
			total[index] /= 2
			continue
		}
		for k, v := range all[index-1] {
			all[index][k+int64(n[i]-'0')] = v
		}
		for j := int64(0); j < int64(n[i]-'0'); j++ {
			for k, v := range ten[index] {
				all[index][k+j] = all[index][k+j]%N + v%N
				all[index][k+j] %= N
			}
		}

		// both values are in >= x00000 range, where x = n[i]
		total[index] += total[index-1] // += 10
		total[index] %= N

		// both values are in < x00000 range , where x = n[i]

		for r := 0; r < int(n[i]-'0'); r++ {
			for l := 0; l <= r; l++ {
				// r is the first digit of y, and l is the first digit of x
				if r == l {
					// we take the count of the 10e
					total[index] += tenans[index]
					total[index] %= N
				} else {
					// y is automatically greater than x
					diff := int64(r - l)
					for k, v := range diffcount[index] {
						if diff+k > 0 {
							total[index] += int64(v)
							total[index] %= N
						}
					}
				}
			}
		}
		// y is in >= x00000 range, and x < x00000 range
		for k, v := range all[index-1] {
			for j := int64(0); j < int64(n[i]-'0'); j++ {
				for p, q := range ten[index] {
					if k + int64(n[i]-'0') > p+j {
						total[index] += int64(v) * int64(q)
						total[index] %= N
					}
				}
			}
		}
	}
}
