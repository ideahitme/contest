package main

import (
    "bufio"
    "os"
	"strconv"
	"fmt"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
    scanner.Split(bufio.ScanWords)

    scanner.Scan()
    numNodes, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    numEdges, _ := strconv.Atoi(scanner.Text())

    g := NewGraph(numNodes)
    for i := 0; i < numEdges; i++ {
		scanner.Scan()
		from, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		to. _ := strconv.Atoi(scanner.Text())
		from--
		to--
		g.AddEdge(from, to)
	}
	sccs := g.SCC()
	mark := make([]int, numNodes)
	for _, scc := range sccs {
		if len(scc) > 1 {
			for _, node := range scc {
				mark[node] = 1
			}
		}
	}
	for _, v := range mark {
		fmt.Printf("%d ", v)
	}
	fmt.Println()
}
