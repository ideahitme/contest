package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const maxInputSize = 512 * 1024 //bytes

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, maxInputSize), maxInputSize)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	// a := make([]int, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		if x%2 == 1 {
			fmt.Println("First")
			return
		}
	}
	fmt.Println("Second")
}
