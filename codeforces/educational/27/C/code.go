package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

const maxTokenSize = 512 * 1024

type seg struct {
	l int
	r int
}

type segments []*seg

func (s segments) Less(i, j int) bool {
	return s[i].l < s[j].l
}

func (s segments) Len() int {
	return len(s)
}

func (s segments) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, maxTokenSize), maxTokenSize)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	var segs []*seg

	for i := 0; i < n; i++ {
		scanner.Scan()
		l, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		r, _ := strconv.Atoi(scanner.Text())
		segs = append(segs, &seg{l: l, r: r})
	}
	sort.Sort(segments(segs))

	a := -1
	b := -1

	for i := 0; i < n; i++ {
		if segs[i].l > a {
			a = segs[i].r
			continue
		}
		if segs[i].l > b {
			b = segs[i].r
			continue
		}
		fmt.Println("NO")
		return
	}

	fmt.Println("YES")
	// 	3
	// 1 2
	// 2 3
	// 4 5
}
