package main

import (
	"bufio"
	"os"
	"strconv"
	"fmt"
	"sort"
)

func main () {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())

	for tt := 0; tt < t; tt++ {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())

		a := make([]int64, n)
		for i := 0; i < n; i++ {
			scanner.Scan()
			a[i], _ = strconv.ParseInt(scanner.Text(), 10, 64)
		}
		sort.Slice(a, func(i, j int) bool{
			return a[i] < a[j]
		})
		answer := int64(0)
		answer += int64(3)*(a[0] + a[n-1])
		for i := 1; i < n-1; i++ {
			answer += 2*a[i]
		}
		div := 6
		if answer % 2 == 0 {
			answer /= 2
			div /= 2
		}
		if answer % 3 == 0 {
			answer /= 3
			div /= 3
		}
		if div == 1 {
			fmt.Println(answer)
		} else {
			fmt.Printf("%d/%d\n", answer, div)
		}
	}
}