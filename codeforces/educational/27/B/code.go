package main

import (
	"bufio"
	"os"
)

const maxTokenSize = 512 * 1024

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, maxTokenSize), maxTokenSize)
}
