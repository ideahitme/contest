package main

import (
	"bufio"
	"os"
	"strconv"
	"fmt"
	"math"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	answer := "-1"
	curMin := math.MaxInt32
	for i := 0; i < n; i++ {
		scanner.Scan()
		name := scanner.Text()
		scanner.Scan()
		price := scanner.Text()
		pprice, _ := strconv.Atoi(price)

		var c4, c7 int
		for i := 0; i < len(price); i++{
			if price[i] == '4' {
				c4++
			}
			if price[i] == '7' {
				c7++
			}
		}

		if c4 == c7 && c4 + c7 == len(price) {
			if pprice < curMin {
				answer = name
				curMin = pprice
			}
		}
	}

	fmt.Println(answer)
}
