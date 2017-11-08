package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 256*1024), 256*1024)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	x := make([]int, n, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		x[i], _ = strconv.Atoi(scanner.Text())
	}

	fmt.Println(topKFrequent(x, k))
}

type Heap struct {
	x [][]int
}

func FromSlice(x [][]int) *Heap {
	h := &Heap{}
	h.x = x
	for i := len(x)/2 - 1; i >= 0; i-- {
		h.heapify(i)
	}
	return h
}

func (h *Heap) heapify(i int) {
	largest := i
	l := 2*i + 1
	r := 2*i + 2
	if l < len(h.x) && h.x[l][1] > h.x[largest][1] {
		largest = l
	}
	if r < len(h.x) && h.x[r][1] > h.x[largest][1] {
		largest = r
	}
	if largest != i {
		h.x[i], h.x[largest] = h.x[largest], h.x[i]
		h.heapify(largest)
	}
}

func (h *Heap) Pop() []int {
	n := len(h.x)
	h.x[0], h.x[n-1] = h.x[n-1], h.x[0]
	res := h.x[n-1]
	h.x = h.x[:n-1]
	h.heapify(0)
	return res
}

func topKFrequent(nums []int, k int) []int {
	hm := map[int]int{}
	for _, n := range nums {
		hm[n]++
	}
	x := make([][]int, 0)
	for key, el := range hm {
		x = append(x, []int{key, el})
	}
	h := FromSlice(x)
	res := make([]int, k)
	for i := 0; i < k; i++ {
		els := h.Pop()
		res[i] = els[0]
	}
	return res
}
