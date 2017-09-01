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
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())
	if n*n < k {
		fmt.Println(-1)
		os.Exit(0)
	}
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		if k == 0 {
			break
		}
		k--
		m[i][i] = 1
		j := i + 1
		for k >= 2 && j < n {
			m[i][j] = 1
			m[j][i] = 1
			k -= 2
			j++
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			fmt.Printf("%d ", m[i][j])
		}
		fmt.Println(m[i][n-1])
	}
}
