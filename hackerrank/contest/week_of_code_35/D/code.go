package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Range struct {
	val  int
	from int
	to   int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	a := make([][]int, n)
	r := make([][]*Range, n)
	pfx := make([][]int, n)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m)
		r[i] = make([]*Range, m)
		dp[i] = make([]int, m)
		pfx[i] = make([]int, m)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			scanner.Scan()
			a[i][j], _ = strconv.Atoi(scanner.Text())
			pfx[i][j] = a[i][j]
			if j > 0 {
				pfx[i][j] += pfx[i][j-1]
			}
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			rr := &Range{}
			sum := a[i][j]
			if j == 0 {
				rr.from = j
				rr.to = j
			} else {
				prev := r[i][j-1]
				previousSum := pfx[i][j-1]
				if prev.from > 0 {
					previousSum -= pfx[i][prev.from-1]
				}

				if prev.to >= j && previousSum >= 0 {
					r[i][j] = prev
					continue
				}

				if prev.to == j-1 && previousSum >= 0 {
					rr.to = j
					rr.from = prev.from
					sum += pfx[i][j-1]
					if prev.from > 0 {
						sum -= pfx[i][prev.from-1]
					}
				}

				if prev.to == j-1 && previousSum < 0 {
					rr.from = j
					rr.to = j
				}

				if prev.to >= j && previousSum < 0 {
					rr.to = prev.to
					rr.from = j
					rr.val = pfx[i][rr.to] - pfx[i][j-1]
					r[i][j] = rr
					continue
				}
			}

			rr.val = sum
			for k := rr.to + 1; k < m; k++ {
				sum += a[i][k]
				if sum >= rr.val {
					rr.val = sum
					rr.to = k
				}
			}
			r[i][j] = rr
		}
	}
	for i := n - 1; i > -1; i-- {
		for j := 0; j < m; j++ {
			if i == n-1 {
				dp[i][j] = r[i][j].val
				continue
			}
			if j > 0 {
				if r[i][j-1].to >= j && r[i][j].from < j {
					dp[i][j] = dp[i][j-1]
					continue
				}
			}
			val := -(1 << 31)
			for k := r[i][j].from; k <= r[i][j].to; k++ {
				if val < dp[i+1][k] {
					val = dp[i+1][k]
				}
			}
			dp[i][j] = val + r[i][j].val
		}
		lmsf := dp[i][0]
		for j := 0; j < m; j++ {
			if j == 0 {
				continue
			}
			if r[i][j-1].to < j && r[i][j].from == j {
				if lmsf+r[i][j].val > dp[i][j] {
					dp[i][j] = lmsf + r[i][j].val
				}
				lmsf = dp[i][j]
			}
			if r[i][j-1].to < j && r[i][j].from < j {
				if lmsf+maxMinDiff(r[i][j-1].val, r[i][j].val) > dp[i][j] {
					dp[i][j] = lmsf + maxMinDiff(r[i][j-1].val, r[i][j].val)
				}
				lmsf = dp[i][j]
			}
			if r[i][j-1].to >= j && r[i][j].from < j {
				dp[i][j] = lmsf
			}
			if r[i][j-1].to >= j && r[i][j].from == j {
				if lmsf+maxMinDiff(r[i][j-1].val, r[i][j].val) > dp[i][j] {
					dp[i][j] = lmsf + maxMinDiff(r[i][j-1].val, r[i][j].val)
				}
				lmsf = dp[i][j]
			}
		}
		rmsf := dp[i][m-1]
		for j := m - 1; j > -1; j-- {
			if j == m-1 {
				continue
			}
			if r[i][j+1].from > j && r[i][j].to == j {
				if rmsf+r[i][j].val > dp[i][j] {
					dp[i][j] = rmsf + r[i][j].val
				}
				rmsf = dp[i][j]
			}
			if r[i][j+1].from > j && r[i][j].to > j {
				if rmsf+maxMinDiff(r[i][j+1].val, r[i][j].val) > dp[i][j] {
					dp[i][j] = rmsf + maxMinDiff(r[i][j+1].val, r[i][j].val)
				}
				rmsf = dp[i][j]
			}
			if r[i][j+1].from <= j && r[i][j].to > j {
				dp[i][j] = max(rmsf, dp[i][j])
				rmsf = dp[i][j]
			}
			if r[i][j+1].from <= j && r[i][j].to == j {
				if rmsf+maxMinDiff(r[i][j+1].val, r[i][j].val) > dp[i][j] {
					dp[i][j] = rmsf + maxMinDiff(r[i][j+1].val, r[i][j].val)
				}
				rmsf = dp[i][j]
			}
		}
	}

	answer := -(1 << 31)
	for j := 0; j < m; j++ {
		if dp[0][j] > answer {
			answer = dp[0][j]
		}
	}
	//fmt.Println(a)
	//fmt.Println(dp)
	fmt.Println(answer)
}

func maxMinDiff(a, b int) int {
	if a < b {
		return 0
	}
	return b - a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
