package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	words := make([]string, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		words[i] = scanner.Text()
	}

	scanner.Scan()
	target := scanner.Text()

	fmt.Println(minStickers(words, target))
}

func minStickers(stickers []string, target string) int {
	s := &solution{stickers: stickers, target: target, mem: make([][]int, len(stickers))}
	answer := s.solve(1<<uint32(len(target))-1, 0)
	if answer >= 1e9 {
		return -1
	}
	return answer
}

type solution struct {
	stickers []string
	mem      [][]int
	target   string
}

func (s *solution) solve(target int, sticker int) int {
	if sticker == len(s.stickers) {
		if target == 0 {
			return 0
		}
		return 1e9
	}

	if s.mem[sticker] == nil {
		s.mem[sticker] = make([]int, 1<<uint32(len(s.target)))
	}
	if s.mem[sticker][target] > 0 {
		return s.mem[sticker][target]
	}

	s.mem[sticker][target] = s.solve(target, sticker+1)

	ntarget := target
	for i := 0; i < len(s.stickers[sticker]); i++ {
		c := s.stickers[sticker][i]
		for j := 0; j < len(s.target); j++ {
			if ntarget&(1<<uint32(j)) != 0 && s.target[j] == c {
				ntarget ^= 1 << uint32(j)
				break
			}
		}
	}

	if target != ntarget {
		s.mem[sticker][target] = min(s.solve(ntarget, sticker)+1, s.mem[sticker][target])
	}
	return s.mem[sticker][target]
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
