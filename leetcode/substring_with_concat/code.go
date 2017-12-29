package main

import "fmt"

func main() {
	//"wordgoodgoodgoodbestword"
	// ["word","good","best","good"]
	fmt.Println(findSubstring("barfoofoobarthefoobarman", []string{"bar", "foo", "the"}))
}

func findSubstring(s string, words []string) []int {
	answer := []int{}
	if len(words) == 0 {
		return answer
	}
	total := map[string]int{}
	for _, word := range words {
		total[word]++
	}
	k := len(words[0])
	for i := 0; i < k; i++ {
		pos := map[string][]int{}
		for _, word := range words {
			pos[word] = []int{}
		}
		cur := i
		from := i
		for cur+k <= len(s) {
			w := s[cur : cur+k]
			if _, ok := pos[w]; !ok {
				cur += k
				from = cur
				continue
			}
			pos[w] = append(pos[w], cur)
			cnt := 0
			for _, posw := range pos[w] {
				if posw >= from {
					cnt++
				}
			}
			if cnt > total[w] {
				from = pos[w][len(pos[w])-total[w]-1] + k
			}
			sts := 0
			for w := range pos {
				cnt := 0
				for _, posw := range pos[w] {
					if posw >= from {
						cnt++
					}
				}
				if cnt < total[w] {
					break
				}
				sts++
			}
			if sts == len(total) {
				answer = append(answer, from)
				from += k
			}
			cur += k
		}
	}

	return answer
}
