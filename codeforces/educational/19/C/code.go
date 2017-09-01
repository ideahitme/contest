package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 512*1024), 512*1024)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()

	s := scanner.Text()
	t := make([][]int, 26)
	res := ""
	buffer := []int{}

	for i, el := range s {
		t[el-97] = append(t[el-97], i)
	}

	j := 0
	for i := 0; i < 26; i++ {
		for len(buffer) != 0 && buffer[len(buffer)-1] <= i {
			res += string(buffer[len(buffer)-1] + 97)
			buffer = buffer[0 : len(buffer)-1]
		}
		var k int
		for k = 0; k < len(t[i]) && t[i][k] < j; k++ {
		}
		for ; k < len(t[i]); k++ {
			res += string(i + 97)
			for f := j; f < t[i][k]; f++ {
				buffer = append(buffer, int(s[f])-97)
			}
			j = t[i][k] + 1
		}
	}
	for i := range buffer {
		res += string(buffer[len(buffer)-1-i] + 97)
	}
	fmt.Println(res)
}
