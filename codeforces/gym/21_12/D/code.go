package main

import (
	"bufio"
	"os"
	"strconv"
)

func main() {
	outstream, err := os.Open("game.out")
	if err != nil {
		panic(err)
	}

	defer outstream.Close()

	instream, err := os.Open("game.in")
	if err != nil {
		panic(err)
	}

	defer instream.Close()

	scanner := bufio.NewScanner(instream)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	if k == 1 {
		outstream.WriteString("Masya")
		return
	}
	if k%2 == 0 {
		if n%(k+1) == 0 {
			outstream.WriteString("Papus")
		} else {
			outstream.WriteString("Masya")
		}
		return
	}

	dp := make([][]bool, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]bool, k+1)
	}
	//dp[i][j] is true if there is i items left, prev take was j and current player making a move is winning
	for i := 1; i <= k; i++ {
		dp[0][i] = false
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			for t := 1; t <= k; t++ {
				if t != j && t <= i {
					dp[i][j] = dp[i][j] || dp[i-t][t]
				}
			}
		}
	}

	//last check
	win := false
	for i := 1; i < k+1; i++ {
		win = !dp[n-i][i] || win
	}
	if win {
		outstream.WriteString("Masya")
	} else {
		outstream.WriteString("Papus")
	}
}
