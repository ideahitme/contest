package main

import "fmt"
import "math"

func main() {
	input := [][]int{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}}
	output := [][]int{{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}}
	res := getSkyline(input)
	for i := range res {
		for j := range res[i] {
			fmt.Printf("expected: %d, got: %d", output[i][j], res[i][j])
		}
		fmt.Printf("\n")
	}
}

func getSkyline(buildings [][]int) [][]int {
	h := NewHeap()
	for _, b := range buildings {
		newB := Building{
			l: b[0],
			r: b[1],
			h: b[2],
		}
		h.Insert(newB)
	}
	return nil
}

type Building struct {
	l, r int
	h    int
}

func (b Building) Less(c Comparable) bool {
	return b.h < c.Value().(int)
}

func (b Building) Value() int {
	return b.h
}

//Max Heap implementation
type Heap struct {
	x []Comparable
}

type Comparable interface {
	Less(x interface{}) bool
	Value() interface{}
}

func NewHeap() Heap {
	x := make([]Comparable, 0)
	return Heap{x}
}

func (h *Heap) Insert(el Comparable) {
	h.x = append(h.x, el)
	i := len(h.x) - 1
	for i > 0 {
		p := int(math.Ceil(float64(i)/2) - 1)
		if h.x[p].Less(h.x[i]) {
			h.x[p], h.x[i] = h.x[i], h.x[p]
			i = p
		} else {
			break
		}
	}
}

func (h *Heap) Pop() Comparable {
	size := len(h.x)
	h.x[0], h.x[size-1] = h.x[size-1], h.x[0]
	last := h.x[size-1]
	h.x = h.x[:size-1]
	size--
	i := 0
	for i < size {
		lc := 2*i + 1 //left child
		rc := 2*i + 2 //right child
		swap := i
		if lc < size && h.x[swap].Less(h.x[lc]) {
			swap = lc
		}
		if rc < size && h.x[swap].Less(h.x[rc]) {
			swap = rc
		}
		if i != swap {
			h.x[i], h.x[swap] = h.x[swap], h.x[i]
			i = swap
		} else {
			break
		}
	}
	return last
}

func (h *Heap) Top() Comparable {
	return h.x[0]
}
