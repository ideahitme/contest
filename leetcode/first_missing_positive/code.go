package main

import "fmt"

func main() {
	fmt.Println(firstMissingPositive([]int{1, 2, 0}))
	fmt.Println(firstMissingPositive([]int{3, 4, -1, 1}))
}

func firstMissingPositive(nums []int) int {
	n := len(nums)
	pos := 0
	for i := 0; i < n; i++ {
		if nums[i] <= 0 {
			nums[i], nums[pos] = nums[pos], nums[i]
			pos++
		}
	}
	nums = nums[pos:]
	n = len(nums)
	for i := 0; i < n; i++ {
		if abs(nums[i])-1 < n && nums[abs(nums[i])-1] > 0 {
			nums[abs(nums[i])-1] = -nums[abs(nums[i])-1]
		}
	}
	for i := 0; i < n; i++ {
		if nums[i] > 0 {
			return (i + 1)
		}
	}

	return n + 1
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
