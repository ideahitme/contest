package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	magicNumber = 317
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	a := make([]int, n+1)
	for i := 0; i < n; i++ {
		scanner.Scan()
		v, _ := strconv.Atoi(scanner.Text())
		a[i+1] = v
	}

	scanner.Scan()
	q, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < q; i++ {
		scanner.Scan()
		p, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		k, _ := strconv.Atoi(scanner.Text())
		ans := 0
		if k >= magicNumber {
			for r := p; r <= n; r += a[r] + k {
				ans++
			}
		} else {

		}
		fmt.Println(ans)
	}
}

/**

n = 8
a = 1,2,3,4,5,6,7,8

p = 1

1. k = 1:

1 -> 1 + a_1 + 1 = 3 -> 3 + a_3 + 1 =

p -> p + a_p + k -> p + a_p + k + a_(p1) + k =

p0 = p
p1 = p0 + a_p0 + k
p2 = p1 + a_p1 + k = p_0 + a_p0 + k + a_p1 + k = p_0+2*k+a_p0+a_p1
p3 = p0+3*k+a_p0+a_p1+a_p2

p_3 - p_2 = k + a_p2


k = 1, all a's are 1s
p -> p + 2 -> p + 4 -> p + 6 -> p + 8 ...

p = 1, a_1 = 2
1 -> 1 + 1 + a_1 = 2 + a_1 = 4 -> 4 + 1 + a_4 = 6 -> 6 + 1 + 1 = 8


*/
