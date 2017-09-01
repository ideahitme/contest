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
	n, _ := strconv.ParseInt(scanner.Text(), 10, 64)

	scanner.Scan()
	k, _ := strconv.ParseInt(scanner.Text(), 10, 64)

	h := n / 2

	p := h / (k + 1)
	d := k * p

	fmt.Println(p, d, (n - p - d))
}
