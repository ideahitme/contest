package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type v struct {
	edges []*edge
	id    int
}

type edge struct {
	v int
	w int
}

type pair struct {
	v   int
	sum int64
}

var ans []int
var a []int
var g []*v
var x []int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		a = make([]int, n)
		ans = make([]int, n)
		x = make([]int, n)
		g = make([]*v, n, n)
		for i := 0; i < n; i++ {
			scanner.Scan()
			a[i], _ = strconv.Atoi(scanner.Text())
			g[i] = &v{make([]*edge, 0), i}
		}
		for i := 0; i < n-1; i++ {
			scanner.Scan()
			var p, w int
			p, _ = strconv.Atoi(scanner.Text())
			scanner.Scan()
			w, _ = strconv.Atoi(scanner.Text())
			g[p-1].edges = append(g[p-1].edges, &edge{i + 1, w})
		}
		root := 0
		stack := make([]*pair, 1)
		stack[0] = &pair{
			v:   root,
			sum: 0,
		}
		dfs(root, stack)
		for i := 0; i < n; i++ {
			fmt.Printf("%d ", ans[i])
		}
		fmt.Print("\n")
	}
}

func dfs(cur int, stack []*pair) {
	l := 0
	r := len(stack) - 1
	totalsum := stack[len(stack)-1].sum
	for l < r {
		mid := (l + r + 1) / 2
		cursum := stack[mid].sum
		if totalsum-cursum <= int64(a[cur]) {
			r = mid - 1
		} else {
			l = mid
		}
	}
	if totalsum-stack[l].sum > int64(a[cur]) {
		x[stack[l].v]--
	}
	t := 0
	lastsum := stack[len(stack)-1].sum
	for _, edge := range g[cur].edges {
		stack = append(stack, &pair{edge.v, lastsum + int64(edge.w)})
		dfs(edge.v, stack)
		stack = stack[:len(stack)-1]
		t += ans[edge.v] + 1
	}
	t += x[cur]
	ans[cur] = t
}
