package main

import (
	"bufio"
	"os"
	"strconv"
	"fmt"
)

func main () {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	max := m * k
	a := make([]int, n)
	b := make([]int, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	for i:=0; i < n; i++ {
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
	}

	for i := 0; i < n; i++ {
		if m * b[i] * a[i] > max {
			max = m*b[i]*a[i]
		}
	}

	fmt.Println(max)
}