package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	fmt.Println(shortestPalindrome("aacecaaa"))
}

func reverse(s string) string {
	bytes := make([]byte, len(s))
	for i := 0; i < len(s); i++ {
		bytes[len(s)-1-i] = s[i]
	}
	return string(bytes)
}

func shortestPalindrome(s string) string {
	if reverse(s) == s {
		return s
	}
	k := &kmp{x: s + "$" + reverse(s)}
	p := k.do()
	end := p[2*len(s)]
	return reverse(s)[:len(s)-end] + s
}

type kmp struct {
	x string
}

func (k *kmp) do() []int {
	p := make([]int, len(k.x))
	border := 0
	for i := 1; i < len(p); i++ {
		for border > 0 && k.x[i] != k.x[border] {
			border = p[border-1]
		}
		if k.x[i] == k.x[border] {
			border++
		} else {
			border = 0
		}
		p[i] = border
	}
	return p
}
