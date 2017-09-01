package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	s := scanner.Text()

	dp := make([][][]bool, n)
	for i := 0; i < n; i++ {
		dp[i] = make([][]bool, 2*k-1)
		for j := 0; j < 2*k-1; j++ {
			dp[i][j] = make([]bool, 3)
		}
	}
	// 0 - W
	// 1 - D
	// 2 - L
	if s[n-1] == '?' {
		dp[n-1][2*k-2][0] = true
		dp[n-1][0][2] = true
	}
	if s[n-1] == 'W' {
		dp[n-1][2*k-2][0] = true
	}
	if s[n-1] == 'L' {
		dp[n-1][0][2] = true
	}
	for i := n - 2; i > -1; i-- {
		if s[i] == '?' {
			for j := 0; j < 2*k-1; j++ {
				if okay(dp[i+1][j]) {
					dp[i][j][1] = true
					if j < 2*k-2 {
						dp[i][j+1][2] = true
					}
					if j > 0 {
						dp[i][j-1][0] = true
					}
				}
			}
		}
		if s[i] == 'W' {
			for j := 0; j < 2*k-1; j++ {
				if okay(dp[i+1][j]) && j > 0 {
					dp[i][j-1][0] = true
				}
			}
		}
		if s[i] == 'L' {
			for j := 0; j < 2*k-1; j++ {
				if okay(dp[i+1][j]) && j < 2*k-2 {
					dp[i][j+1][2] = true
				}
			}
		}
		if s[i] == 'D' {
			for j := 0; j < 2*k-1; j++ {
				if okay(dp[i+1][j]) {
					dp[i][j][1] = true
				}
			}
		}
	}
	answer := make([]rune, n)
	cur := k - 1
	for i := 0; i < n; i++ {
		c := find(dp[i][cur])
		if c == 'X' {
			fmt.Println("NO")
			os.Exit(0)
		}
		answer[i] = c
		if c == 'W' {
			cur++
		}
		if c == 'L' {
			cur--
		}
	}
	fmt.Println(string(answer))
}

func okay(x []bool) bool {
	for _, xx := range x {
		if xx {
			return true
		}
	}
	return false
}

func find(x []bool) rune {
	for i, xx := range x {
		if xx {
			if i == 0 {
				return 'W'
			}
			if i == 1 {
				return 'D'
			}
			if i == 2 {
				return 'L'
			}
		}
	}
	return 'X'
}
