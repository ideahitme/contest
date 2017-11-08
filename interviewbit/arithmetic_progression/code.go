package main

import "fmt"

func main() {
	a := []int{3, 4, 5, 8, 12, 16}
	fmt.Println(solve(a))
}
func solve(a []int) int {
	n := len(a)
	dp := make([]map[int]int, n)
	if n == 0 {
		return 0
	}
	answer := 1
	for j := 0; j < n; j++ {
		dp[j] = make(map[int]int)
		for i := 0; i < j; i++ {
			x := a[j] - a[i]
			max := 0
			if val, ok := dp[i][x]; !ok {
				max = 1
			} else {
				max = val
			}
			dp[j][x] = max + 1
			if dp[j][x] > answer {
				answer = dp[j][x]
			}
		}
	}
	// fmt.Println(dp)
	return answer
}
