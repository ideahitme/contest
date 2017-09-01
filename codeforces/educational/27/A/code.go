package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

const maxTokenSize = 512 * 1024

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, maxTokenSize), maxTokenSize)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	a := make([]int, 2*n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		a[2*i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		a[2*i+1], _ = strconv.Atoi(scanner.Text())
	}

	sort.Ints(a)
	if a[n-1] < a[n] {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
