package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const maxInputSize = 512 * 1024 //bytes

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, maxInputSize), maxInputSize)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	s := scanner.Text()

	yes := true
	l := make([]int, 26)

	for i := 0; i < n; i++ {
		l[s[i]-97]++
		if l[s[i]-97] > k {
			yes = false
		}
	}

	if yes {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
