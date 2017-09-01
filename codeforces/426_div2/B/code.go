package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	capacity := 8 * 1024 * 1024
	s.Buffer(make([]byte, capacity), capacity)
	s.Split(bufio.ScanWords)

	s.Scan()
	s.Text()

	s.Scan()
	k, _ := strconv.Atoi(s.Text())

	s.Scan()
	d := s.Text()

	f := make([]int, 26)
	l := make([]int, 26)
	for i := range f {
		l[i] = -1
		f[i] = -1
	}
	for i, c := range d {
		l[c-65] = i
		if f[c-65] == -1 {
			f[c-65] = i
		}
	}
	t := make([]int, len(d))
	for i := 0; i < 26; i++ {
		if f[i] != -1 {
			t[f[i]]++
		}
		if l[i] != -1 && l[i]+1 < len(d) {
			t[l[i]+1]--
		}
	}
	var m, cur int
	for i := 0; i < len(d); i++ {
		cur = cur + t[i]
		if m < cur {
			m = cur
		}
	}
	if m > k {
		fmt.Println("YES")
		return
	}
	fmt.Println("NO")
}
