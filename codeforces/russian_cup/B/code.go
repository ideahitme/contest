package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const (
	max = math.MaxInt32
	min = math.MinInt32
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < t; i++ {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		m, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		k, _ := strconv.Atoi(scanner.Text())
		a := make([][]int, n)
		for j := 0; j < n; j++ {
			a[j] = make([]int, m)
		}
		for j := 0; j < n; j++ {
			for l := 0; l < m; l++ {
				scanner.Scan()
				ax, _ := strconv.Atoi(scanner.Text())
				a[j][l] = ax
			}
		}
		possible := true
		for j := 0; j < n; j++ {
			for l := 0; l < m; l++ {
				if a[j][l] != 0 {
					a[j][l] = (j+l)%k + 1
				}
			}
		}
		for j := 0; j < n; j++ {
			cont := 0
			for l := 0; l < m; l++ {
				if a[j][l] == 0 {
					cont = 0
					continue
				}
				cont++
				if cont > k {
					possible = false
				}
			}
		}
		for l := 0; l < m; l++ {
			cont := 0
			for j := 0; j < n; j++ {
				if a[j][l] == 0 {
					cont = 0
					continue
				}
				cont++
				if cont > k {
					possible = false
				}
			}
		}
		if !possible {
			fmt.Println("NO")
		} else {
			fmt.Println("YES")
			for j := 0; j < n; j++ {
				for l := 0; l < m; l++ {
					fmt.Printf("%d ", a[j][l])
				}
				fmt.Printf("\n")
			}
		}
	}
}
