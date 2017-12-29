package main

import (
	"fmt"
)

func main(){
	fmt.Println(trap([]int{4,2,0,3,2,5}))
}

type e struct {
	h int
	l int
	pos int
}

func trap(height []int) int {
	n := len(height)
	s := make([]*e, 0)
	total := 0
	for i := 1; i < n; i ++ {
		if height[i] > height[i-1] {
			for len(s) > 0 && s[len(s)-1].h <= height[i] {
				total += (i-s[len(s)-1].pos)*(s[len(s)-1].h-s[len(s)-1].l)
				s = s[:len(s)-1]
			}
			if len(s) > 0 {
				total += (i-s[len(s)-1].pos)*(height[i]-s[len(s)-1].l)
				s[len(s)-1].l = height[i]
			}
		}
		if height[i] < height[i-1] {
			s = append(s, &e{h: height[i-1], l: height[i], pos: i})
		}
	}
	return total
}