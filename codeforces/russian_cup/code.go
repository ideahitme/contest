package main

import (
	"bufio"
	"fmt"
	"math"
	"math/rand"
	"os"
	"strconv"
	"time"
)

const (
	max = math.MaxInt32
	min = math.MinInt32
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())
	for pp := 0; pp < t; pp++ {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		k, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		q, _ := strconv.Atoi(scanner.Text())
		qs := make([][]int, q)
		c := make([]int, q)
		for i := 0; i < q; i++ {
			scanner.Scan()
			c[i], _ = strconv.Atoi(scanner.Text())
		}
		for i := 0; i < q; i++ {
			scanner.Scan()
			size, _ := strconv.Atoi(scanner.Text())
			qs[i] = make([]int, size)
			for j := 0; j < size; j++ {
				scanner.Scan()
				x, _ := strconv.Atoi(scanner.Text())
				qs[i][j] = x
			}
		}
		next := calcNext(qs, k, n)
		dp := make([]int, q)
		dp[q-1] = 0
		r := q - 1
		t := NewTree(&Config{AllowDuplicates: true})
		t.InsertIndex(q-1, 0)
		fmt.Println(next)
		for i := q - 2; i >= 0; i-- {
			newR := next[i]
			for j := r; j > newR; j-- {
				t.Remove(dp[j])
			}
			r = newR
			if r == i {
				dp[i] = c[i+1] + dp[i+1]
			} else {
				node := t.Min()
				dp[i] = c[node.index] + node.key
				fmt.Println(i, node.index, node.key)
			}
			t.Insert(dp[i])
		}
		fmt.Println(dp)
	}
}

func calcNext(qs [][]int, k, n int) []int {
	next := make([]int, len(qs))
	cum := make([]int, n+1)
	card := 0
	l := 0
	r := -1
	for r < len(qs) {
		if card <= k {
			if r == len(qs)-1 {
				break
			}
			r++
			for _, el := range qs[r] {
				if cum[el] == 0 {
					card++
				}
				cum[el]++
			}
		}
		if card > k {
			next[l] = r - 1
			for _, el := range qs[l] {
				cum[el]--
				if cum[el] == 0 {
					card--
				}
			}
			l++
		}
	}
	for i := l; i < len(qs); i++ {
		next[i] = len(qs) - 1
	}
	return next
}

// Config generic configs for all Treaps
type Config struct {
	AllowDuplicates bool //allow only unique keys in the treap
}

// DefaultConfig configuration for most of the cases
var DefaultConfig = Config{AllowDuplicates: true}

// Node storage for treap node
type Node struct {
	parent *Node
	left   *Node
	right  *Node
	key    int
	p      int //priority - randomized value
	size   int
	value  int
	index  int
}

// NewNode returns new node with randomly generated `p` value
func NewNode(key int) *Node {
	p := int(rand.Int31n(math.MaxInt32))
	return &Node{key: key, p: p, size: 1}
}

// NewNodeWithValue returns new node with additional field for value. Used for `Slice` Treap with element index acting as node key
func NewNodeWithValue(key, value int) *Node {
	n := NewNode(key)
	n.value = value
	return n
}

// SetParent sets parent for a given node, if the node is non-nil
func (n *Node) SetParent(p *Node) {
	if n != nil {
		n.parent = p
	}
}

// Size returns size of the subtree including current node
func (n *Node) Size() int {
	if n == nil {
		return 0
	}
	return n.size
}

// Tree is the most simple implementation of treap
type Tree struct {
	root *Node
	cfg  *Config
	size int
}

/** Public methods */

// NewTree returns Tree object with nil root
func NewTree(cfg *Config) *Tree {
	rand.Seed(time.Now().UTC().UnixNano())
	return &Tree{
		cfg:  cfg,
		size: 0,
	}
}

// Insert adds values to the Treap
func (t *Tree) Insert(x ...int) {
	for _, el := range x {
		if !t.cfg.AllowDuplicates && t.find(t.root, el) {
			continue
		}
		newNode := NewNode(el)
		l, r := t.split(t.root, el)
		t.root = t.merge(l, newNode)
		t.root = t.merge(t.root, r)
		t.size++
	}
}

// Insert adds values to the Treap
func (t *Tree) InsertIndex(index, el int) {
	newNode := NewNode(el)
	newNode.index = index
	l, r := t.split(t.root, el)
	t.root = t.merge(l, newNode)
	t.root = t.merge(t.root, r)
	t.size++
}

// Find finds if value is present in the Treap
func (t *Tree) Find(x int) bool {
	return t.find(t.root, x)
}

// Slice returns sorted slice by InOrder traversing
func (t *Tree) Slice() []int {
	result := make([]int, 0, t.size)
	t.inOrder(t.root, func(cur *Node) {
		result = append(result, cur.key)
	})
	return result
}

// Remove deletes node with key == x from the Treap
// if multiple such elements exist only one is deleted
func (t *Tree) Remove(x int) {
	l, r := t.split(t.root, x-1)
	xl, xr := t.split(r, x)
	if xl != nil {
		l = t.merge(l, xl.left)
		xr = t.merge(xl.right, xr)
	}
	t.root = t.merge(l, xr)
}

// RemoveAll deletes all node with key == x from the Treap
func (t *Tree) RemoveAll(x int) {
	l, r := t.split(t.root, x-1)
	_, xr := t.split(r, x)
	t.root = t.merge(l, xr)
}

func (t *Tree) Min() *Node {
	cur := t.root
	for cur.left != nil {
		cur = cur.left
	}
	return cur
}

/** Private methods */

// split recursively splits the treap with a given root into two Treaps l, r based on key
// l - has all node keys less or equal to key
// r - has all node keys strictly greater than key
func (t *Tree) split(root *Node, key int) (l *Node, r *Node) {
	if root == nil {
		return
	}
	if root.key > key {
		subL, subR := t.split(root.left, key)
		subR.SetParent(root)
		root.left = subR
		return subL, root
	}
	subL, subR := t.split(root.right, key)
	subL.SetParent(root)
	root.right = subL
	return root, subR
}

// merge recursively merges two Treaps into one, maintaining Treap property
// produces new root
// it is required that every key in one of the Treaps is less than any key in another Treap
func (t *Tree) merge(l, r *Node) (root *Node) {
	if l == nil {
		return r
	}
	if r == nil {
		return l
	}
	if l.key > r.key {
		l, r = r, l
	}
	if l.p > r.p {
		subR := t.merge(l.right, r)
		subR.SetParent(l)
		l.right = subR
		return l
	}
	subL := t.merge(l, r.left)
	subL.SetParent(r)
	r.left = subL
	return r
}

func (t *Tree) inOrder(cur *Node, f func(cur *Node)) {
	if cur == nil {
		return
	}
	t.inOrder(cur.left, f)
	f(cur)
	t.inOrder(cur.right, f)
}

func (t *Tree) find(cur *Node, x int) bool {
	if cur == nil {
		return false
	}
	if cur.key == x {
		return true
	}
	if cur.key > x {
		return t.find(cur.left, x)
	}
	return t.find(cur.right, x)
}
