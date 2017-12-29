package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	UL int = iota
	UR
	R
	LR
	LL
	L
)

func printMove(move int) string {
	switch move {
	case UL:
		return "UL"
	case UR:
		return "UR"
	case R:
		return "R"
	case LR:
		return "LR"
	case LL:
		return "LL"
	case L:
		return "L"
	}
	return ""
}

func previousPosition(i, j int, move int) (x, y int) {
	switch move {
	case UL:
		return i + 2, j + 1
	case UR:
		return i + 2, j - 1
	case R:
		return i, j - 2
	case LR:
		return i - 2, j - 1
	case LL:
		return i - 2, j + 1
	case L:
		return i, j + 2
	}
	return -1, -1
}

type node struct {
	from int
	dist int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	b := make([][]*node, n)
	for i := 0; i < n; i++ {
		b[i] = make([]*node, n)
		for j := 0; j < n; j++ {
			b[i][j] = &node{}
		}
	}
	scanner.Scan()
	fx, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	fy, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	tx, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	ty, _ := strconv.Atoi(scanner.Text())

	if fx == tx && fy == ty {
		fmt.Println(0)
		return
	}

	bfs(b, fx, fy)

	if b[tx][ty].dist == 0 {
		fmt.Println("Impossible")
		return
	}

	fmt.Println(b[tx][ty].dist)
	moves := []string{}
	for tx != fx || ty != fy {
		moves = append(moves, printMove(b[tx][ty].from))
		tx, ty = previousPosition(tx, ty, b[tx][ty].from)
	}
	for i := len(moves) - 1; i > -1; i-- {
		fmt.Printf(moves[i] + " ")
	}
	fmt.Println()
}

func bfs(b [][]*node, fx, fy int) {
	queue := make([][2]int, 0)
	queue = append(queue, [2]int{fx, fy})
	b[fx][fy].dist = 0
	for len(queue) > 0 {
		curx := queue[0][0]
		cury := queue[0][1]
		queue = queue[1:]
		curdist := b[curx][cury].dist
		for i := 0; i < 6; i++ {
			if newx, newy, ok := checkAndCompare(b, curx, cury, i); ok {
				b[newx][newy].dist = curdist + 1
				b[newx][newy].from = i
				queue = append(queue, [2]int{newx, newy})
			}
		}
	}
}

func checkAndCompare(b [][]*node, i, j int, move int) (int, int, bool) {
	var newx, newy int
	switch move {
	case UL:
		newx, newy = i-2, j-1
	case UR:
		newx, newy = i-2, j+1
	case R:
		newx, newy = i, j+2
	case LR:
		newx, newy = i+2, j+1
	case LL:
		newx, newy = i+2, j-1
	case L:
		newx, newy = i, j-2
	}
	if !okayBoundary(newx, len(b)) || !okayBoundary(newy, len(b)) {
		return 0, 0, false
	}
	if b[newx][newy].dist != 0 {
		return 0, 0, false
	}
	return newx, newy, true
}

func okayBoundary(i, n int) bool {
	return 0 <= i && i <= n-1
}
