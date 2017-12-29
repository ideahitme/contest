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

	for i := 0; i < q; i++ {
		scanner.Scan()
		n, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		n--
		scanner.Scan()
		k, _ := strconv.ParseInt(scanner.Text(), 10, 64)

		coef := binCoef(1001)

		fmt.Println(solve(n, k, coef))
	}
}

func binCoef(k int64) [][]int64 {
	c := make([][]int64, k+1)
	for i := int64(0); i < k+1; i++ {
		c[i] = make([]int64, k+1)
		for j := int64(0); j < min(i+1, k+1); j++ {
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

func solve(n, k int64, coef [][]int64) int64 {
	mtrx := make([][]int64, k+2)
	for i := int64(0); i < k+2; i++ {
		mtrx[i] = make([]int64, k+2)
		for j := i; j < k+2; j++ {
			if i == j && i == 0 {
				mtrx[i][j] = 1
				continue
			}
			if i == 0 {
				mtrx[i][j] = coef[k][j-1]
				continue
			}
			mtrx[i][j] = coef[k-i+1][j-i]
		}
	}

	nmtrx := raise(mtrx, n-1)
	answer := int64(0)
	for i := 0; i < len(nmtrx); i++ {
		answer += nmtrx[0][i]
		answer %= N
	}

	answer -= 1
	if answer < 0 {
		answer += N
	}

	return answer
}

func iden(k int) [][]int64 {
	c := make([][]int64, k)
	for i := 0; i < k; i++ {
		c[i] = make([]int64, k)
		for j := 0; j < k; j++ {
			if i == j {
				c[i][j] = 1
			}
		}
	}
	return c
}

func raise(mtrx [][]int64, n int64) [][]int64 {
	res := iden(len(mtrx))
	for n > 0 {
		if n%2 == 0 {
			mtrx = mult(mtrx, mtrx)
			n /= 2
		} else {
			res = mult(res, mtrx)
			n--
		}
	}

	return res
}

func mult(a, b [][]int64) [][]int64 {
	res := make([][]int64, len(a))
	for i := 0; i < len(res); i++ {
		res[i] = make([]int64, len(res))
		for j := 0; j < len(res); j++ {
			for k := 0; k < len(res); k++ {
				res[i][j] += a[i][k] * b[k][j]
				res[i][j] %= N
			}
		}
	}

	return res
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
