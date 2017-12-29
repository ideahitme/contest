package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type edge struct {
	from int
	to   int
	w    int
}

type minmax struct {
	min int
	max int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	graph := make([][]*edge, n)
	edges := make([]*edge, m)
	for i := 0; i < m; i++ {
		scanner.Scan()
		u, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		v, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		w, _ := strconv.Atoi(scanner.Text())
		u--
		v--
		graph[u] = append(graph[u], &edge{to: v, w: w})
		edges[i] = &edge{from: u, to: v, w: w}
	}

	t := newTarjan(graph)
	t.SCC()
	sccs := make([]int, n)
	for i := 0; i < len(t.sccs); i++ {
		for _, v := range t.sccs[i] {
			sccs[v] = i
		}
	}
	mm := make([]*minmax, len(t.sccs))
	for i := 0; i < len(t.sccs); i++ {
		mm[i] = &minmax{}
		mm[i].min = 1e9 + 1
		mm[i].max = -1
	}
	mme := make([][]*edge, len(t.sccs))
	for _, e := range edges {
		u := e.from
		gu := sccs[u]
		v := e.to
		gv := sccs[v]
		if gu == gv {
			mm[gu].min = min(mm[gu].min, e.w)
			mm[gv].max = max(mm[gv].max, e.w)
			continue
		}
		mme[gu] = append(mme[gu], &edge{to: gv, w: e.w})
	}
	d := newMinMax(mm, mme)
	d.findMinMax()
	fmt.Println(d.answer)
}

type doMinMax struct {
	mm      []*minmax
	mme     [][]*edge
	visited []bool
	answer  int
}

func newMinMax(mm []*minmax, mme [][]*edge) *doMinMax {
	return &doMinMax{
		mm:      mm,
		mme:     mme,
		visited: make([]bool, len(mm)),
	}
}

func (d *doMinMax) findMinMax() {
	for i := 0; i < len(d.mm); i++ {
		d.dfs(i)
	}
}

func (d *doMinMax) dfs(cur int) {
	if d.visited[cur] {
		return
	}
	absmax := d.mm[cur].max
	absmin := d.mm[cur].min
	for _, n := range d.mme[cur] {
		absmin = min(absmin, n.w)
		absmax = max(absmax, n.w)
		d.dfs(n.to)
		absmin = min(absmin, d.mm[n.to].min)
		absmax = max(absmax, d.mm[n.to].max)
		d.answer = max(d.answer, max(max(d.mm[cur].max, n.w), d.mm[n.to].max)-min(min(d.mm[cur].min, n.w), d.mm[n.to].min))
	}
	d.mm[cur].max = absmax
	d.mm[cur].min = absmin
	d.visited[cur] = true
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

type tarjan struct {
	graph     [][]*edge
	time      int
	ord       []int
	anc       []int
	isInStack []bool
	stack     []int
	sccs      [][]int
}

func newTarjan(graph [][]*edge) *tarjan {
	return &tarjan{
		graph:     graph,
		time:      0,
		ord:       make([]int, len(graph)),
		anc:       make([]int, len(graph)),
		isInStack: make([]bool, len(graph)),
		stack:     []int{},
	}
}

func (t *tarjan) SCC() {
	n := len(t.graph)
	for i := 0; i < n; i++ {
		if t.ord[i] == 0 {
			t.dfs(i)
		}
	}
}

func (t *tarjan) dfs(cur int) {
	t.time++
	t.ord[cur] = t.time
	t.anc[cur] = t.time
	t.isInStack[cur] = true
	t.stack = append(t.stack, cur)
	for i := 0; i < len(t.graph[cur]); i++ {
		e := t.graph[cur][i]
		if t.ord[e.to] == 0 {
			t.dfs(e.to)
			t.anc[cur] = min(t.anc[cur], t.anc[e.to])
		} else if t.isInStack[e.to] {
			t.anc[cur] = min(t.anc[cur], t.ord[e.to])
		}
	}
	if t.ord[cur] == t.anc[cur] {
		scc := []int{}
		for true {
			last := t.stack[len(t.stack)-1]
			scc = append(scc, last)
			t.stack = t.stack[:len(t.stack)-1]
			t.isInStack[last] = false
			if last == cur {
				break
			}
		}
		t.sccs = append(t.sccs, scc)
	}
}
