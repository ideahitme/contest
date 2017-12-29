package main

import (
	"bufio"
	"fmt"
	"net/http"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	words := make([]string, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		words[i] = scanner.Text()
	}

	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < m; i++ {
		scanner.Scan()
		fmt.Println(minAbbreviation(scanner.Text(), words))
	}

	http.DefaultClient.Do()
}

func minAbbreviation(target string, dictionary []string) string {
	m := []int{}
	n := len(target)
	for _, w := range dictionary {
		if len(w) != n {
			continue
		}
		x := 0
		for i := 0; i < n; i++ {
			if w[n-1-i] == target[n-i-1] {
				x |= 1 << uint(i)
			}
		}
		m = append(m, x)
	}

	if len(m) == 0 {
		return fmt.Sprintf("%d", n)
	}

	minAbbr := n
	index := -1
	for i := 0; i < 1<<uint(n); i++ {
		f := true
		for j := 0; j < len(m); j++ {
			if m[j]|i <= m[j] {
				f = false
				break
			}
		}
		if !f {
			continue
		}
		zero := 0
		total := 0
		for j := 0; j < n; j++ {
			if i&(1<<uint(j)) == 0 {
				zero++
			} else {
				total++
				if zero > 0 {
					total++
					zero = 0
				}
			}
		}
		if zero > 0 {
			total++
		}
		if total < minAbbr {
			minAbbr = total
			index = i
		}
	}

	if index == -1 {
		return target
	}

	s := strconv.FormatInt(int64(index|1<<uint(n)), 2)
	answer := ""
	zero := 0
	for j := 1; j < len(s); j++ {
		if s[j] == '0' {
			zero++
		} else {
			if zero > 0 {
				answer += fmt.Sprintf("%d", zero)
				zero = 0
			}
			answer += string(target[j-1])
		}
	}
	if zero > 0 {
		answer += fmt.Sprintf("%d", zero)
	}

	return answer
}
