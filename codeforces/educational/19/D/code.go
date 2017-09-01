package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const (
	max = math.MaxInt32
	min = math.MinInt32
)

var goods map[int]bool
var all map[int]int

func main() {
	goods = map[int]bool{}
	all = map[int]int{}

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	nodes := make([]*node, n)
	notRoot := make([]bool, n)
	for i := 0; i < n; i++ {
		nodes[i] = &node{}
	}
	for i := 0; i < n; i++ {
		var v, l, r int
		scanner.Scan()
		v, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		l, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		r, _ = strconv.Atoi(scanner.Text())
		nodes[i].v = v
		all[v]++
		if l != -1 {
			nodes[i].l = nodes[l-1]
			notRoot[l-1] = true
		}
		if r != -1 {
			nodes[i].r = nodes[r-1]
			notRoot[r-1] = true
		}
	}
	var root *node
	for i, b := range notRoot {
		if !b {
			root = nodes[i]
			break
		}
	}
	dfs(root, min, max)
	total := 0

	for k := range all {
		if !goods[k] {
			total += all[k]
		}
	}
	fmt.Println(total)
}

type node struct {
	v int
	l *node
	r *node
}

func _min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
func _max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func dfs(cur *node, min, max int) {
	if cur == nil {
		return
	}
	if cur.v >= min && cur.v <= max {
		goods[cur.v] = true
	}
	dfs(cur.l, min, _min(cur.v, max))
	dfs(cur.r, _max(cur.v, min), max)
}
