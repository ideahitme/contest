package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	s := make([]string, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		s[i] = scanner.Text()
	}
	scanner.Scan()
	target := scanner.Text()
	fmt.Println(minStickers(s, target))
}

func minStickers(stickers []string, target string) int {
	t := [26]byte{}
	c := [26]byte{}
	for i := 0; i < len(target); i++ {
		t[target[i] - 'a']++
	}
	m := make([][26]byte, len(stickers))
	for i := 0; i < len(stickers); i++ {
		for j := 0; j < len(stickers[i]); j++ {
			m[i][stickers[i][j]-'a']++
			c[stickers[i][j]-'a'] += 15
		}
	}

	if !satisfy(c, t) {
		return -1
	}



	dp := make([][]int, len(stickers))
	for i := 0; i < len(stickers); i++ {
		dp[i] = make([]int, 1 << uint(len(target)))
	}

	return dfs(dp, m,  0, 0, target)
}

func dfs(dp [][]int, m [][26]byte, i, mask int, target string) int {
	if i == len(m) {
		if mask == (1 << uint(len(target))) - 1 {
			return 0
		}
		return 1e9
	}
	if dp[i][mask] > 0 {
		return dp[i][mask]
	}
	a := dfs(dp, m, i+1, mask, target)
	nmask := mask
	for j := 0; j < 26; j++ {
		c := m[i][j]
		for c > 0 {
			f := false
			for q := 0; q < len(target); q++ {
				if target[q] == 'a' + byte(j) && (nmask & (1 << uint(q))) == 0 {
					nmask |= 1 << uint(q)
					f = true
					break
				}
			}
			if !f {
				break
			}
			c--
		}
	}
	b := int(1e9)
	if nmask != mask {
		b = dfs(dp, m, i, nmask, target) + 1
	}
	if a < b {
		dp[i][mask] = a
		return a
	}
	dp[i][mask] = b
	return b
}

func satisfy(a, b [26]byte) bool {
	for i := 0; i < 26; i++ {
		if a[i] < b[i] {
			return false
		}
	}

	return true
}

