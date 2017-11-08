package main

import (
	"fmt"
	"strconv"
)

func main() {
	fmt.Println(nextClosestTime("23:59"))
}

func nextClosestTime(time string) string {
	set := map[int]struct{}{}
	a, _ := strconv.Atoi(time[0:1])
	b, _ := strconv.Atoi(time[1:2])
	c, _ := strconv.Atoi(time[3:4])
	d, _ := strconv.Atoi(time[4:5])

	set[a] = struct{}{}
	set[b] = struct{}{}
	set[c] = struct{}{}
	set[d] = struct{}{}
	given := time[0:2] + time[3:5]

	curDiff := 1000000
	curBest := ""
	for a, _ := range set {
		for b, _ := range set {
			for c, _ := range set {
				for d, _ := range set {
					newStr := fmt.Sprintf("%d%d%d%d", a, b, c, d)
					if newStr == given {
						continue
					}
					if !valid(newStr) {
						continue
					}
					thisDiff := diff(newStr, given)
					if thisDiff < curDiff {
						curDiff = thisDiff
						curBest = newStr
					}
				}
			}
		}
	}
	if curBest == "" {
		curBest = given
	}
	return curBest[0:2] + ":" + curBest[2:4]

}

func diff(x, y string) int {
	a, _ := strconv.Atoi(x)
	b, _ := strconv.Atoi(y)

	as := 3600*(a/100) + 60*(a%100)
	bs := 3600*(b/100) + 60*(b%100)
	f := as - bs
	if f < 0 {
		f += 24 * 3600
	}
	return f
}

func valid(y string) bool {
	x, _ := strconv.Atoi(y)
	if x/100 >= 24 {
		return false
	}
	if x%100 >= 60 {
		return false
	}
	return true
}
