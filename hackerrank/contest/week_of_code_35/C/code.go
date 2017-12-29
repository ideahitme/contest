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
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)

	scanner.Scan()
	h, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	w, _ := strconv.Atoi(scanner.Text())

	s := make([][]int, h)
	for i := 0; i < h; i++ {
		s[i] = make([]int, w)
	}

	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			scanner.Scan()
			s[i][j], _ = strconv.Atoi(scanner.Text())
		}
	}

	surface := 2 * h * w

	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			for k := 1; k <= s[i][j]; k++ {
				if visible(s, i+1, j, k) {
					surface++
				}
				if visible(s, i-1, j, k) {
					surface++
				}
				if visible(s, i, j+1, k) {
					surface++
				}
				if visible(s, i, j-1, k) {
					surface++
				}
			}
		}
	}

	fmt.Println(surface)
}

func visible(s [][]int, i, j, k int) bool {
	h := len(s)
	w := len(s[0])
	if i >= h || j >= w {
		return true
	}
	if i < 0 || j < 0 {
		return true
	}
	return s[i][j] < k
}
