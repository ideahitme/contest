package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 2048*2048), 2048*2048)
	scanner.Split(bufio.ScanWords)

	l := &List{}
	l.Insert(-1, 1e9)
	l.Print()
}

type Node struct {
	from   int
	to     int
	height int
	next   *Node
}

type List struct {
	head *Node
}

func (l *List) Insert(pos, height int) {
	start := pos
	end := pos + height
	if l.head == nil {
		l.head = &Node{from: start, to: end, height: height}
		return
	}
	cur := l.head
	var prev *Node
	var next *Node
	for cur != nil || cur.to <= start {
		prev = cur
		cur = cur.next
	}
	for cur != nil || cur.from < end {
		next = cur
		cur = cur.next
	}

}

func (l *List) Print() {
	cur := l.head
	for cur != nil {
		fmt.Printf("| from: %d, to: %d |", cur.from, cur.to)
	}
	fmt.Print("\n")
}
