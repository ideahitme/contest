package main

import "fmt"

var dp [][][]string

func main() {
	fmt.Println(displayDiff("a2_3b42c_78d", "a_34c27_8ed"))
}

func displayDiff(o, n string) string {
	dp = make([][][]string, len(o)+1)
	for i := 0; i < len(o)+1; i++ {
		dp[i] = make([][]string, len(n)+1)
		for j := 0; j < len(n)+1; j++ {
			dp[i][j] = make([]string, 2)
		}
	}
	// a := "same_prefix(_1)23[12]3_same_suffix"
	// b := "same_prefix(_)[23]123(3)_same_suffix"
	// fmt.Println(comp(&a, &b))
	res1 := concat(&o, &n, 0, 0, 0, "")
	res2 := concat(&o, &n, 0, 0, 1, "")
	return *min(&res1, &res2)
	// return ""
}

// a(2)_3(b)4(2)c(_)[2]7[_]8[e]d

func concat(o, n *string, i, j, turn int, res string) string {
	if i == len(*o) && j == len(*n) {
		dp[i][j][turn] = res
		return res
	}
	if i == len(*o) {
		return res + "[" + (*n)[j:] + "]"
	}
	if j == len(*n) {
		return res + "(" + (*o)[i:] + ")"
	}
	if dp[i][j][turn] != "" {
		// return dp[i][j][turn]
	}
	iterated := false
	for i < len(*o) && j < len(*n) && (*o)[i] == (*n)[j] {
		iterated = true
		res += string((*o)[i])
		i++
		j++
	}
	if iterated {
		return concat(o, n, i, j, turn, res)
	}
	if turn == 0 {
		ii := i + 1
		qmin := ""
		for ii < len(*o) {
			if qmin == "" {
				qmin = concat(o, n, ii, j, 1, res+"("+(*o)[i:ii]+")")
			} else {
				cand := concat(o, n, ii, j, 1, res+"("+(*o)[i:ii]+")")
				qmin = *(min(&qmin, &cand))
				if ii == 13 {
					fmt.Println(i, ii, (*o)[i:ii])
					fmt.Println(cand, "!!", qmin, "!!", res+"("+(*o)[i:ii]+")")
				}
			}
			ii++
		}
		dp[i][j][turn] = qmin
		return qmin
	} else {
		ii := j + 1
		qmin := ""
		for ii <= len(*n) {
			// ii++
			if qmin == "" {
				qmin = concat(o, n, i, ii, 0, res+"["+(*n)[j:ii]+"]")
			} else {
				cand := concat(o, n, i, ii, 0, res+"["+(*n)[j:ii]+"]")
				qmin = *(min(&qmin, &cand))
			}
			ii++
		}
		dp[i][j][turn] = qmin
		return qmin
	}
	return ""
}

func min(a, b *string) *string {
	if comp(a, b) > 0 {
		return a
	}
	return b
}

func comp(a, b *string) int {
	if leng(a) < leng(b) {
		return 1
	}
	if leng(a) > leng(b) {
		return -1
	}
	i := 0
	for i < len(*a) && i < len(*b) && (*a)[i] == (*b)[i] {
		i++
	}
	if i == len(*a) && i == len(*b) {
		return 0
	}
	if i == len(*a) {
		return 1
	}
	if i == len(*b) {
		return -1
	}
	return ord((*a)[i]) - ord((*b)[i])
}

func ord(t byte) int {
	if t == '(' {
		return 4
	}
	if t == ')' {
		return 3
	}
	if t == '[' {
		return 2
	}
	if t == ']' {
		return 1
	}
	return -int(t) + 1000
}

func leng(x *string) int {
	res := 0
	for _, t := range *x {
		if t == '(' || t == ')' || t == ']' || t == '[' {
			continue
		}
		res++
	}
	return res
}
