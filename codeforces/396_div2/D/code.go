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
	numbers := make(map[int]bool, m)
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		if _, exist := numbers[n-num]; exist {
			fmt.Println(1)
			os.Exit(0)
		}
		numbers[num] = true
	}
	fmt.Println(0)
}
