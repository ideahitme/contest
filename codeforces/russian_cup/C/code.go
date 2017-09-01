package main

import (
	"bufio"
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

}
