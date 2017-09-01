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
	scanner.Scan()
	n, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	scanner.Scan()
	k, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	if k == 1 {
		fmt.Println(n)
		os.Exit(0)
	}

	sqrt := int64(math.Sqrt(float64(n))) + 1
	var gcd int64
	for i := int64(1); i <= sqrt; i++ {
		if n%i != 0 {
			continue
		}
		if fit(n, i, k) {
			if i > gcd {
				gcd = i
			}
		}
		if fit(n, n/i, k) {
			if n/i > gcd {
				gcd = n / i
			}
		}
	}
	if gcd == 0 {
		fmt.Println(-1)
		os.Exit(0)
	}
	for i := int64(1); i < k; i++ {
		fmt.Printf("%d ", i*gcd)
	}
	fmt.Println(n - (k*(k-1)*gcd)/2)
}

func fit(n, d, k int64) bool {
	if k > 10e6 {
		return false
	}
	if (k-1)*(k+2) > 10e10 {
		return false
	}
	if k*d > 10e10 {
		return false
	}
	if (k-1)*(k+2)*d >= 2*n {
		return false
	}
	return true
}
