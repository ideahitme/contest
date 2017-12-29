package main

import "fmt"

//
//[[1,3],[6,9]]
//[2,5]
func main() {
	fmt.Println(insert([]Interval{{Start:1, End:3},{Start:6, End:9}}, Interval{Start:2, End:5}))
}
type Interval struct {
   Start int
   End   int
}

func insert(intervals []Interval, newInterval Interval) []Interval {
	curInterval := newInterval
	answer := []Interval{}
	n := len(intervals)
	inserted := false
	for i := 0; i < n; i++ {
		interval := intervals[i]
		if interval.End < curInterval.Start {
			answer = append(answer, interval)
			continue
		}
		if interval.Start > curInterval.End {
			answer = append(answer, curInterval)
			inserted = true
			answer = append(answer, intervals[i:]...)
			break
		}
		curInterval.Start = min(interval.Start, curInterval.Start)
		curInterval.End = max(interval.End, curInterval.End)
	}
	if !inserted {
		answer = append(answer, curInterval)
	}

	return answer
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}