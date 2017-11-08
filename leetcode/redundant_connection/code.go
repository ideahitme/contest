package main

import "fmt"

var cycle [][]int

func main() {
	// [[2,7],[7,8],[3,6],[2,5],[6,8],[4,8],[2,8],[1,8],[7,10],[3,9]]
	fmt.Println(findRedundantConnection([][]int{
		[]int{2, 7},
		[]int{7, 8},
		[]int{3, 6},
		[]int{2, 5},
		[]int{6, 8},
		[]int{4, 8},
		[]int{2, 8},
		[]int{1, 8},
		[]int{7, 10},
		[]int{3, 9},
	}))
}

func findRedundantConnection(edges [][]int) []int {
	n := len(edges)
	cycles := make([][]int, 0)
	cycle := &cycles
	graph := make([][]int, n)

	for i := 0; i < len(edges); i++ {
		u := edges[i][0]
		v := edges[i][1]
		u--
		v--
		graph[u] = append(graph[u], v)
		graph[v] = append(graph[v], u)
	}

	mark := make([]bool, n)
	dfs(0, -1, graph, mark, cycle)
	fmt.Println(cycle)

	for i := n - 1; i > -1; i-- {
		u := edges[i][0]
		v := edges[i][1] // u < v
		for j := 0; j < len(*cycle); j++ {
			uu := (*cycle)[j][0] + 1
			vv := (*cycle)[j][1] + 1
			if uu > vv {
				uu, vv = vv, uu
			}
			if uu == u && vv == v {
				return []int{uu, vv}
			}
		}
	}
	//
	return nil
}

func dfs(cur, from int, graph [][]int, mark []bool, cycle *[][]int) int {
	mark[cur] = true
	for _, n := range graph[cur] {
		if n == from {
			continue
		}
		if mark[n] {
			*cycle = append(*cycle, []int{cur, n})
			return n
			// return
		}
		if x := dfs(n, cur, graph, mark, cycle); x != -1 {
			*cycle = append(*cycle, []int{cur, n})
			if x == cur {
				return -1
			}
			return x
		}
	}
	return -1
}
