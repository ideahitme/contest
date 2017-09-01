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
	m, _ := strconv.Atoi(scanner.Text())

	a := make([]int, n)
	l := make([]int, m)

	i := 0
	for scanner.Scan() {
		l[i], _ = strconv.Atoi(scanner.Text())
		l[i]--
		i++
	}

	mm := map[int]int{}
	for i := 0; i < m-1; i++ {
		tmp := (l[i+1] - l[i]) % n
		if tmp <= 0 {
			tmp += n
		}
		if a[l[i]] != 0 && a[l[i]] != tmp {
			fmt.Println(-1)
			return
		}
		a[l[i]] = tmp
		if j, ok := mm[a[l[i]]]; ok && j != l[i] {
			fmt.Println(-1)
			return
		}
		mm[a[l[i]]] = l[i]
	}

	// fill in zeroes
	for i := 0; i < n; i++ {
		if a[i] != 0 {
			continue
		}
		for j := 1; j <= n; j++ {
			if _, ok := mm[j]; !ok {
				mm[j] = i
				a[i] = j
				break
			}
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d ", a[i])
	}
	fmt.Println()
}
