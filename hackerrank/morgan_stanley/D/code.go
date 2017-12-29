package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type stock struct {
	l int64
	r int64
	i int64
	s int64
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	s := make([]*stock, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		s[i] = &stock{}
		s[i].s, _ = strconv.ParseInt(scanner.Text(), 10, 64)
		s[i].i = int64(i)
	}
	for i := 0; i < n; i++ {
		scanner.Scan()
		s[i].l, _ = strconv.ParseInt(scanner.Text(), 10, 64)
		s[i].l = int64(i) - s[i].l
	}
	for i := 0; i < n; i++ {
		scanner.Scan()
		s[i].r, _ = strconv.ParseInt(scanner.Text(), 10, 64)
		s[i].r = int64(i) + s[i].r
	}

	dp := make([]int64, n)
	ans := int64(-1)
	for i := 0; i < n; i++ {
		dp[i] += s[i].s
		for j := s[i].l - 1; j >= 0; j-- {
			if s[j].r < int64(i) {
				dp[i] = max(dp[i], s[i].s+dp[j])
			}
		}
		ans = max(ans, dp[i])
	}

	fmt.Println(ans)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
