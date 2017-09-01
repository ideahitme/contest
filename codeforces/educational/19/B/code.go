package main

import (
	"bufio"
	"errors"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	x := make([]int, 0, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())
		x = append(x, y)
	}
	sort.Ints(x)
	oddH := NewMaxHeap()
	evenH := NewMaxHeap()

	for _, el := range x {
		if el%2 == 0 {
			curOddMax, errOdd := oddH.Top()
			if errOdd == nil {
				oddH.Insert(curOddMax + el)
			}
			curEvenMax, errEven := evenH.Top()
			if errEven == nil {
				evenH.Insert(curEvenMax + el)
			}
			evenH.Insert(el)
		} else {
			curEvenMax, errEven := evenH.Top()
			curOddMax, errOdd := oddH.Top()
			if errEven == nil {
				oddH.Insert(curEvenMax + el)
			}
			if errOdd == nil {
				evenH.Insert(curOddMax + el)
			}
			oddH.Insert(el)
		}
		// fmt.Println(el, evenH, oddH)
	}
	max, _ := oddH.Top()
	fmt.Println(max)
}

type Heap struct {
	arr []int // supplementary array of elements
	cmp cmp
}

func NewMaxHeap() *Heap {
	arr := []int{}
	return &Heap{
		arr: arr,
		cmp: &max{},
	}
}

func NewMinHeap() *Heap {
	arr := []int{}
	return &Heap{
		arr: arr,
		cmp: &min{},
	}
}

func (h *Heap) Insert(x int) {
	h.arr = append(h.arr, x)
	i := len(h.arr) - 1
	for i > 0 {
		p := h.parent(i)
		if h.pushUp(i, p) {
			i = p
			continue
		}
		break
	}
}

func (h *Heap) Pop() (int, error) {
	if len(h.arr) == 0 {
		return 0, errors.New("heap is empty")
	}

	popped := h.arr[0]
	h.arr[0], h.arr[len(h.arr)-1] = h.arr[len(h.arr)-1], h.arr[0]
	h.arr = h.arr[0 : len(h.arr)-1]
	i := 0
	for i < len(h.arr) {
		lc := h.leftChild(i)
		if lc < len(h.arr) && h.pushUp(lc, i) {
			i = lc
			continue
		}

		rc := h.rightChild(i)
		if rc < len(h.arr) && h.pushUp(rc, i) {
			i = rc
			continue
		}

		break
	}
	return popped, nil
}

func (h *Heap) Top() (int, error) {
	if len(h.arr) == 0 {
		return 0, errors.New("heap is empty")
	}
	return h.arr[0], nil
}

func (h *Heap) parent(i int) int {
	return int(math.Ceil(float64(i)/2)) - 1
}

func (h *Heap) leftChild(i int) int {
	return 2*i + 1
}

func (h *Heap) rightChild(i int) int {
	return 2*i + 2
}

func (h *Heap) pushUp(child, parent int) bool {
	if h.cmp.NeedSwap(h.arr[child], h.arr[parent]) {
		h.arr[child], h.arr[parent] = h.arr[parent], h.arr[child]
		return true
	}
	return false
}

type cmp interface {
	NeedSwap(child, parent int) bool
}

type max struct{}

func (m *max) NeedSwap(child, parent int) bool {
	return child > parent
}

type min struct{}

func (m *min) NeedSwap(child, parent int) bool {
	return child < parent
}
