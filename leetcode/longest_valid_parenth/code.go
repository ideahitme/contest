package main

import "fmt"

func main() {
	fmt.Println(longestValidParentheses(")()())"))
}

func longestValidParentheses(s string) int {
	dp := make([]int, len(s))
	if len(s) == 0 {
		return 0
	}
	dp[0] = -1
	for i := 1; i < len(s); i++ {
		if s[i] == '(' {
			dp[i] = -1
			continue
		}
		if s[i-1] == '(' {
			if i == 1 {
				dp[i] = 0
				continue
			}
			if dp[i-2] == -1 {
				dp[i] = i - 1
				continue
			}
			dp[i] = dp[i-2]
			continue
		}
		if s[i-1] == ')' {
			j := -1
			cur := i - 1
			for true {
				l := dp[cur]
				if l == -1 || l == 0 {
					break
				}
				if s[l-1] == '(' {
					j = l - 1
					if l > 1 && dp[l-2] != -1 {
						j = dp[l-2]
					}
					break
				}
				cur = l - 1
			}
			dp[i] = j
		}
	}
	answer := -1
	for i := 0; i < len(s); i++ {
		if dp[i] != -1 && answer < (i-dp[i]+1) {
			answer = i - dp[i] + 1
		}
	}
	if answer == -1 {
		return 0
	}
	return answer
}
