package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type entry struct {
	index int
	sval  string
	ival  string
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanLines)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	s := make([]string, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		s[i] = scanner.Text()
	}

	scanner.Scan()
	ln := scanner.Text()

	coln, _ := strconv.Atoi(strings.Split(ln, " ")[0])
	reverse := strings.Split(ln, " ")[1] == "true"
	lex := strings.Split(ln, " ")[2] == "lexicographic"

	es := make([]*entry, n)

	for i := 0; i < n; i++ {
		e := &entry{}
		e.index = i
		e.sval = strings.Split(s[i], " ")[coln-1]
		e.ival = strings.TrimLeft(e.sval, "0")
		es[i] = e
	}

	sort.Slice(es, func(i, j int) bool {
		var less bool
		if lex {
			less = es[i].sval < es[j].sval
		} else {
			less = fnLess(es[i].ival, es[j].ival) || (es[i].ival == es[j].ival && es[i].index < es[j].index)
		}
		if reverse {
			return !less
		}
		return less
	})

	for i := 0; i < n; i++ {
		fmt.Println(s[es[i].index])
	}
}

func fnLess(x, y string) bool {
	if len(x) < len(y) {
		return true
	}
	if len(x) > len(y) {
		return false
	}
	for i := 0; i < len(x); i++ {
		if x[i] < y[i] {
			return true
		}
		if x[i] > y[i] {
			return false
		}
	}
	return false
}