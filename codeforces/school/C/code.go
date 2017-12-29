package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	s := scanner.Text()
	f := strings.Split(s, ":")
	scanner.Scan()
	n, _ := strconv.Atoi(f[0])
	scanner.Scan()
	m, _ := strconv.Atoi(f[1])

	if n < m {
		n, m = m, n
	}
	if m == 0 {
		fmt.Println(0)
		return
	}
	if n == m {
		fmt.Println(n - 1)
		return
	}
	fmt.Println(m)
	return
}
