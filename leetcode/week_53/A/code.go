package main

import (
	"bufio"
	"os"
	"fmt"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	//fmt.Println(hasAlternatingBits(4))
	//fmt.Println(hasAlternatingBits(5))
	//fmt.Println(hasAlternatingBits(7))
	//fmt.Println(hasAlternatingBits(11))
	//fmt.Println(hasAlternatingBits(10))
}


func hasAlternatingBits(n int) bool {
	p := n | (n << 1)
	if n % 2 == 0 {
		p++
	}
	return n & (n << 1) == 0 && p & (p + 1) == 0
}
