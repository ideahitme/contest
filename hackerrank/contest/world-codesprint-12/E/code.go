package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"

	"sort"
)

type animal struct {
	t    int
	from int
	to   int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())
	for t > 0 {
		t--
		scanner.Scan()
		z, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())
		a := make([]*animal, 0)
		typ := make([]string, n)
		from := make([]int, n)
		to := make([]int, n)
		for i := 0; i < n; i++ {
			scanner.Scan()
			typ[i] = scanner.Text()
		}
		for i := 0; i < n; i++ {
			scanner.Scan()
			from[i], _ = strconv.Atoi(scanner.Text())
			from[i]--
		}
		for i := 0; i < n; i++ {
			scanner.Scan()
			to[i], _ = strconv.Atoi(scanner.Text())
			to[i]--
		}
		for i := 0; i < n; i++ {
			if to[i] > from[i] {
				an := &animal{from: from[i], to: to[i]}
				if typ[i] == "E" || typ[i] == "C" {
					an.t = 1
				} else {
					an.t = 0
				}
				a = append(a, an)
			}
		}
		solve(a, z)
	}

}

func solve(a []*animal, z int) {
	sort.Slice(a, func(i, j int) bool {
		if a[i].from < a[j].from {
			return true
		}
		if a[i].from == a[j].from && a[i].to < a[j].to {
			return true
		}
		return false
	})

	ends := make([][]*animal, z)
	starts := make([][]*animal, z)
	for i := 0; i < len(a); i++ {
		ends[a[i].to] = append(ends[a[i].to], a[i])
		starts[a[i].from] = append(ends[a[i].from], a[i])
	}
	dp := make([][3]int, z)
	for i := 0; i < len(a); i++ {
		cur := a[i]
		m := max(dp[cur.from][2], dp[cur.from][cur.t])
		for j := cur.from + 1; j <= cur.to; j++ {
			for _, as := range ends[j] {
				if as.from >= cur.from && as.t == cur.t {
					m++
				}
			}
			dp[j][cur.t] = max(dp[j][cur.t], m)
		}
		for j := cur.to; j < z; j++ {
			dp[j][2] = max(dp[j][2], m)
		}
	}
	ans := make([]int, len(a)+1)
	for i := 0; i < len(ans); i++ {
		ans[i] = -1
	}
	for i := 0; i < z; i++ {
		p := dp[i][0]
		q := dp[i][1]
		r := dp[i][2]
		if ans[p] == -1 {
			ans[p] = i + 1
		}
		if ans[q] == -1 {
			ans[q] = i + 1
		}
		if ans[r] == -1 {
			ans[r] = i + 1
		}
	}
	for i := 1; i < len(ans); i++ {
		fmt.Printf("%d ", ans[i])
	}
	fmt.Println()
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
