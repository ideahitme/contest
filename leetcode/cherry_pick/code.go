package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	grid := make([][]int, n)
	for i := 0; i < n; i++ {
		grid[i] = make([]int, n)
		for j := 0; j < n; j++ {
			scanner.Scan()
			grid[i][j], _ = strconv.Atoi(scanner.Text())
		}
	}
	fmt.Println(cherryPickup(grid))
}

func cherryPickup(grid [][]int) int {
	n := len(grid)

	// calculate prefix sums

	psum := make([][]int, n)
	for i := 0; i < n; i++ {
		psum[i] = make([]int, n)
		for j := 0; j < n; j++ {
			if j == 0 {
				psum[i][j] = grid[i][j]
			} else {
				psum[i][j] = grid[i][j] + psum[i][j-1]
			}
		}
	}

	dp := make([][][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([][]int, n)
		for j := 0; j < n; j++ {
			dp[i][j] = make([]int, n)
		}
	}

	for k := 0; k < n; k++ {
		// calc dp[i][j][k]
		if grid[0][k] == -1 {
			for l := k; l < n; l++ {
				for j := 0; j <= l; j++ {
					dp[0][j][l] = -1
				}
			}
			break
		}
		for j := 0; j <= k; j++ {
			dp[0][j][k] = psum[0][k]
		}
	}

	for i := 1; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := j; k < n; k++ {
				if grid[i][k] == -1 || grid[i][j] == -1 {
					dp[i][j][k] = -1
					continue
				}
				if k == 0 {
					if dp[i-1][j][k] != -1 {
						dp[i][j][k] = dp[i-1][j][k] + grid[i][k]
					} else {
						dp[i][j][k] = -1
					}
					continue
				}
				if k > j {
					if dp[i-1][j][k] == -1 {
						if dp[i][j][k-1] == -1 {
							dp[i][j][k] = -1
							continue
						}
						dp[i][j][k] = dp[i][j][k-1] + grid[i][k]
					} else {
						cand := make([]int, 0)
						for l := j; l > -1; l-- {
							if grid[i][l] == -1 {
								break
							}
							if dp[i-1][l][k] == -1 {
								continue
							}
							ncand := dp[i-1][l][k]
							ncand += psum[i][j]
							if l > 0 {
								ncand -= psum[i][l-1]
							}
							cand = append(cand, ncand)
						}
						if len(cand) != 0 {
							dp[i][j][k] = max(cand...) + grid[i][k]
						} else {
							dp[i][j][k] = -1
						}
						if dp[i][j][k-1] != -1 {
							dp[i][j][k] = max(dp[i][j][k-1]+grid[i][k], dp[i][j][k])
						}
					}
				}
				if k == j {
					cand := make([]int, 0)
					if dp[i-1][j][k] != -1 {
						cand = append(cand, dp[i-1][j][k]+grid[i][k])
					}
					if dp[i][j-1][k] != -1 {
						cand = append(cand, dp[i][j-1][k])
					}
					dp[i][j][k] = max(cand...)
				}
			}
		}
	}
	if dp[n-1][n-1][n-1] == -1 {
		return 0
	}
	return dp[n-1][n-1][n-1]
}

func max(nums ...int) int {
	max := -1
	for _, num := range nums {
		if num > max {
			max = num
		}
	}
	return max
}
