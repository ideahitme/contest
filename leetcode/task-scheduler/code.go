package main

import (
	"fmt"
)

func main() {
	head := &ListNode{1, nil}
	cur := head
	for i := 2; i <= 3; i++{
		cur.Next = &ListNode{i, nil}
		cur = cur.Next
	}

	n := reverseKGroup(head,2)
	for n != nil {
		fmt.Printf("%d->", n.Val)
		n = n.Next
	}
}
 type ListNode struct {
	 Val int
	 Next *ListNode
 }

 func length(head *ListNode) int {
 	total := 0
 	cur := head
 	for cur != nil {
 		cur = cur.Next
 		total++
	}
	return total
 }

func reverseKGroup(head *ListNode, k int) *ListNode {
	n := length(head)
	c := 0
	cur := head
	nHead := &ListNode{}
	ptail := nHead
	for cur != nil {
		c++
		nptail := cur
		ptail.Next = cur
		if n - c < k - 1 {
			return nHead.Next
		}

		prev := cur
		cur = cur.Next
		l := k-1
		for cur != nil && l > 0 {
			ptail.Next = cur
			cNext := cur.Next
			cur.Next = prev
			prev = cur
			cur = cNext
			l--
			c++
		}
		ptail = nptail
	}
	ptail.Next = nil
	return nHead.Next
}