package main

import "fmt"

func main() {
	fmt.Println(checkValidString("((*(()))"))
}

func checkValidString(s string) bool {
	n := len(s)
	if n == 0 {
		return true
	}
	dp := make([][]bool, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]bool, n)
	}
	for i := 0; i < n; i++ {
		if s[i] == '*' {
			dp[i][i] = true
		}
	}
	for l := 1; l < n; l++ {
		for i := 0; i < n-l; i++ {
			j := i + l
			if s[j] == '(' {
				dp[i][j] = false
				continue
			}
			if s[i] == ')' {
				dp[i][j] = false
				continue
			}
			if l == 1 {
				dp[i][j] = true
				continue
			}
			if dp[i+1][j-1] {
				dp[i][j] = true
				continue
			}
			for k := 0; k < l; k++ {
				dp[i][j] = dp[i][j] || dp[i][i+k] && dp[i+k+1][j]
			}
		}
	}
	return dp[0][n-1]
}
