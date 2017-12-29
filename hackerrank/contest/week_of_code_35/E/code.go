package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const N = int64(1e9 + 9)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Scan()
	q, _ := strconv.Atoi(scanner.Text())
	bern := bernoulli()
	bin := binCoef(1002)
	for i := 0; i < q; i++ {
		scanner.Scan()
		n, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		n--
		scanner.Scan()
		k, _ := strconv.ParseInt(scanner.Text(), 10, 64)

		fmt.Println(solve(n, k, bern, bin))
	}
}

func binCoef(k int64) [][]int64 {

	c := make([][]int64, k+1)
	for i := int64(0); i < k+1; i++ {
		c[i] = make([]int64, i+1)
		for j := int64(0); j < i+1; j++ {
			if j == 0 || j == i {
				c[i][j] = 1
				continue
			}
			c[i][j] = c[i-1][j-1] + c[i-1][j]
			c[i][j] %= N
		}
	}
	return c
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func solve(n, k int64, bern []int64, binCoef [][]int64) int64 {
	if n == 0 {
		return 0
	}
	answer := int64(0)
	pn := make([]int64, k+2)
	pn[0] = 1
	for i := int64(1); i < k+2; i++ {
		pn[i] = (n % N) * pn[i-1]
		pn[i] %= N
	}
	revk := inverse(k + 1)
	for i := int64(0); i < k+1; i++ {
		m := binCoef[k+1][i]
		m *= bern[i]
		m %= N
		m *= pn[k+1-i]
		m %= N
		answer += m
		answer %= N
	}
	answer *= revk
	answer %= N
	answer -= 1
	if answer < 0 {
		answer += N
	}
	return answer
}

func inverse(a int64) int64 {
	return pow(a, N-2)
}

func pow(a, n int64) int64 {
	if n == 0 {
		return 1
	}
	p := pow(a, n/2) % N
	p = (p * p) % N
	if n%2 == 1 {
		p *= a
		p %= N
	}
	return p
}

func bernoulli() []int64 {
	b := make([]int64, 1001)
	b[0] = 1
	for i := int64(1); i < 1001; i++ {
		fact := int64(1)
		sum := int64(0)
		for j := int64(0); j < i; j++ {
			if j > 0 {
				fact *= i - j + 1
				fact %= N
				fact *= inverse(j)
				fact %= N
			}
			bot := inverse(i - j + 1)
			bot *= fact
			bot %= N
			sum += bot * b[j]
			sum %= N
		}
		b[i] = 1 - sum
		if b[i] < 0 {
			b[i] += N
		}
	}
	return b
}
