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
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)

	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < t; i++ {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		r, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		p, _ := strconv.Atoi(scanner.Text())

		fn := float64(n)
		fr := float64(r)
		fp := float64(p)

		answer := 0

		for fn < fp {
			fn = (1 + r/100.0) * fn
			answer++
		}

		fmt.Println(answer)
	}

}
