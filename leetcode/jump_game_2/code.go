package main

import "fmt"

func main() {
	fmt.Println(jump([]int{1, 2, 0, 5, 0, 3}))
}

func jump(nums []int) int {
	jmp := make([]int, len(nums))
	n := len(jmp)
	for i := range jmp {
		jmp[i] = i
	}
	for i, num := range nums {
		if i+num >= len(nums) {
			num = len(nums) - i - 1
		}
		jmp[i+num] = min(i, jmp[i+num])
	}
	curMin := n
	for i := n - 1; i > -1; i-- {
		if jmp[i] > curMin {
			jmp[i] = curMin
		} else {
			curMin = jmp[i]
		}
	}
	total := 0
	i := n - 1
	for i != 0 {
		if i == jmp[i] {
			i--
		} else {
			i = jmp[i]
		}
		total++
	}
	return total
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
