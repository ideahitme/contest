package main

import (
	"bufio"
	"os"
)

const maxInputSize = 512 * 1024 //bytes

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, maxInputSize), maxInputSize)

}
