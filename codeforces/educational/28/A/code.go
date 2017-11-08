package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const maxTokenSize = 512 * 1024

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, maxTokenSize), maxTokenSize)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	a := make([]int, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}

	minTotal := n

	for i := 0; i <= n; i++ {
		localTotal := 0
		for j := 0; j < i; j++ {
			if a[j] != 0 {
				localTotal++
			}
		}
		for j := i; j < n; j++ {
			if a[j] != 1 {
				localTotal++
			}
		}
		if localTotal < minTotal {
			minTotal = localTotal
		}
	}

	fmt.Println(n - minTotal)
}
