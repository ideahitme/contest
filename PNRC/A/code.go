package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	word := scanner.Text()
	vals := make([]int, 0, len(word))
	dp := make([]int, len(word))
	dp[0] = 1
	for _, r := range word {
		vals = append(vals, int(r-97))
	}
	gmax := 1
	for i := 1; i < len(word); i++ {
		lmax := 0
		for j := 0; j < i; j++ {
			if dp[j] > lmax && vals[i] > vals[j] {
				lmax = dp[j]
			}
		}
		dp[i] = lmax + 1
		if gmax < dp[i] {
			gmax = dp[i]
		}
	}
	fmt.Println(26 - gmax)
}
