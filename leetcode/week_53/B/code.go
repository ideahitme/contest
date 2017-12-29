package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	fmt.Println(maxAreaOfIsland([][]int{
		[]int{1, 1, 1, 0, 1},
		[]int{1, 1, 1, 0, 1},
		[]int{1, 1, 1, 0, 1},
		[]int{1, 1, 1, 0, 1},
	}))
}

func maxAreaOfIsland(grid [][]int) int {
	n := len(grid)
	m := len(grid[0])
	visited := make([][]bool, n)
	result := make([][]int, n)
	for i := 0; i < n; i++ {
		visited[i] = make([]bool, m)
		result[i] = make([]int, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 1 {
				dfs(i, j, grid, visited, result)
			}
		}
	}

	answer := -1

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if result[i][j] > answer {
				answer = result[i][j]
			}
		}
	}

	return answer
}

func dfs(i, j int, grid [][]int, visited [][]bool, result [][]int) int {
	if i < 0 || i >= len(visited) {
		return 0
	}
	if j < 0 || j >= len(visited[0]) {
		return 0
	}

	if visited[i][j] {
		return 0
	}
	visited[i][j] = true

	if grid[i][j] == 0 {
		return 0
	}

	result[i][j] = 1
	result[i][j] += dfs(i+1, j, grid, visited, result)
	result[i][j] += dfs(i-1, j, grid, visited, result)
	result[i][j] += dfs(i, j-1, grid, visited, result)
	result[i][j] += dfs(i, j+1, grid, visited, result)

	return result[i][j]
}
