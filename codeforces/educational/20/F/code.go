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
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	x := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		x[i], _ = strconv.Atoi(scanner.Text())
	}
	fmt.Println(x)
}
