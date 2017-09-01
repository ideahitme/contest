package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 0, 1024*1024), 1024*1024)
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())
	x := make([]int, 0)
	for scanner.Scan() {
		s := scanner.Text()
		cur := 0
		for _, r := range s {
			cur++
			if r == '-' {
				x = append(x, cur)
				cur = 0
			}
		}
		cur++ //include last space
		x = append(x, cur)
	}
	x[len(x)-1]-- //remove the very last space

	var maxWord, total int
	for _, xx := range x {
		total += xx
		if xx > maxWord {
			maxWord = xx
		}
	}
	// fmt.Println(x)
	// fmt.Println(count(x, 8))
	l := maxWord
	r := total
	for l < r {
		m := (l + r) / 2
		if count(x, m) <= k {
			r = m
			continue
		}
		l = m + 1
	}
	fmt.Println(l)
}

func count(x []int, l int) int {
	total := 1
	cur := 0
	for _, xx := range x {
		if cur+xx > l {
			total++
			cur = 0
		}
		cur += xx
	}
	return total
}
