package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)

	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < t; i++ {
		scanner.Scan()
		n, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		scanner.Scan()
		r, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		scanner.Scan()
		p, _ := strconv.ParseInt(scanner.Text(), 10, 64)

		fn := float64(n)
		fr := float64(r)
		fp := float64(p)

		ll := int64(0)
		rr := int64(1e5)

		for ll < rr {
			m := int64((ll + rr) / 2)
			if fn*math.Pow(1.0+fr/100.0, float64(m)) < fp {
				ll = m + 1
			} else {
				rr = m
			}
		}

		fmt.Printf("Case %d: %d\n", (i + 1), ll)
	}
}
