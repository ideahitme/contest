package main

import (
	"bufio"
	"os"
	"strconv"
	"fmt"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 2048*2048),2048*2048 )

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	mtr := make([][]int, n)
	for i := 0; i < n; i++{
		mtr[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			mtr[i][j] = i
		}
	}
	for j := 0; j < n; j++ {
		for i := j; i < n; i++ {
			mtr[i][j] = j
		}
	}

	for j := 0; j < n; j++ {
		for i := 0; i < n; i++ {
			mtr[i][j] = m + (k + 1)*mtr[i][j] - max(i, j)
		}
	}

	print(mtr)
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func print(mtr [][]int) {
	n := len(mtr)
	m := len(mtr[0])
	for i := 0; i < n; i++{
		for j := 0; j < m; j++ {
			fmt.Printf("%d ", mtr[i][j])
		}
		fmt.Print("\n")
	}
}
