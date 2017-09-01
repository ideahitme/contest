package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const maxInputSize = 512 * 1024 //bytes
var answer []*edge
var graph [][]*edge
var d []int
var marked []bool

type edge struct {
	index int
	to    int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, maxInputSize), maxInputSize)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	graph = make([][]*edge, n)
	d = make([]int, n)
	marked = make([]bool, n)

	total := 0
	for i := 0; i < n; i++ {
		scanner.Scan()
		d[i], _ = strconv.Atoi(scanner.Text())
		if d[i] == 1 {
			total++
		}
	}
	for i := 0; i < m; i++ {
		scanner.Scan()
		u, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		v, _ := strconv.Atoi(scanner.Text())

		graph[u-1] = append(graph[u-1], &edge{
			to:    v - 1,
			index: (i + 1),
		})
		graph[v-1] = append(graph[v-1], &edge{
			to:    u - 1,
			index: (i + 1),
		})
	}

	for i := 0; i < n; i++ {
		if d[i] == -1 {
			if total%2 == 1 {
				d[i] = 1
				total = 0
				continue
			}
			d[i] = 0
		}
	}

	if total%2 == 1 {
		fmt.Println(-1)
		return
	}

	traverse(0)
	fmt.Println(len(answer))
	for _, e := range answer {
		fmt.Println(e.index)
	}
}

func traverse(cur int) int {
	marked[cur] = true

	counted := 0
	for _, e := range graph[cur] {
		if marked[e.to] {
			continue
		}
		t := traverse(e.to)

		if t == 1 {
			counted++
			answer = append(answer, e)
		}
	}

	if d[cur]%2 != counted%2 {
		return 1
	}
	return 0
}
