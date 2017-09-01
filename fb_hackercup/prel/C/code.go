package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func initDP() map[int][][]float64 {
	dp := map[int][][]float64{}

	maxT := 20
	diceSize := []int{2, 4, 6, 8, 10, 12, 20}
	for _, dice := range diceSize {
		dp[dice] = make([][]float64, maxT+1)
		dp[dice][1] = make([]float64, dice+1)
		for i := 1; i <= dice; i++ {
			dp[dice][1][i] = 1.0 / float64(dice)
		}
		for throws := 2; throws <= maxT; throws++ {
			dp[dice][throws] = make([]float64, dice*throws+1)
			for i := 1; i <= dice*throws; i++ {
				for diceSide := 1; diceSide <= dice; diceSide++ {
					if i >= diceSide && i-diceSide <= dice*(throws-1) {
						dp[dice][throws][i] += dp[dice][throws-1][i-diceSide] / float64(dice)
					}
				}
			}
		}
	}
	return dp
}

func main() {
	dp := initDP()
	writeFile, err := os.Create("output")
	if err != nil {
		panic(err)
	}
	defer writeFile.Close()

	writer := bufio.NewWriter(writeFile)
	defer writer.Flush()

	file, err := os.Open("input")
	if err != nil {
		panic(err)
	}
	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		for i := 0; i < n; i++ {
			var answer float64
			scanner.Scan()
			h, _ := strconv.Atoi(scanner.Text())
			scanner.Scan()
			s, _ := strconv.Atoi(scanner.Text())
			for j := 0; j < s; j++ {
				var prob float64
				scanner.Scan()
				t, d, z, isPlus := readTDZ(scanner)
				goal := 0
				if isPlus {
					goal = h - z
				} else {
					goal = h + z
				}
				if goal <= 0 {
					prob = 1.0
				} else {
					for f := goal; f <= t*d; f++ {
						prob += dp[d][t][f]
					}
				}
				if answer < prob {
					answer = prob
				}
			}
			writer.WriteString(strconv.FormatFloat(answer, 'f', -1, 64) + "\n")
		}
	}
}

func readTDZ(scanner *bufio.Scanner) (t, d, z int, isPlus bool) {
	line := scanner.Text()
	lines := strings.Split(line, "d")
	t, _ = strconv.Atoi(lines[0])
	dz := strings.Split(lines[1], "+")
	if len(dz) > 1 {
		isPlus = true
		d, _ = strconv.Atoi(dz[0])
		z, _ = strconv.Atoi(dz[1])
	} else {
		dz = strings.Split(lines[1], "-")
		d, _ = strconv.Atoi(dz[0])
		if len(dz) > 1 {
			z, _ = strconv.Atoi(dz[1])
		}
	}
	return
}
