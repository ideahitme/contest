import sys

class Node:
	def __init__(self, data, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right


def inOrder(root):
	if root is None:
		return
	if root.left is not None:
		inOrder(root.left)
	print root.data,	
	if root.right is not None:
		inOrder(root.right)

def inOrderWithoutRecursion(root):
	if root is None:
		return	
	stack = [root]
	cur = stack[-1]
	while len(stack) > 0:
		while cur is not None and cur.left is not None:
			stack.append(cur.left)
			cur = cur.left
		node = stack.pop()
		print node.data,
		cur = node.right		
		if cur is not None: stack.append(cur)

def do_swap(root, swap_level):
	curs = [root]
	lvl = 0 
	while len(curs) > 0:
		lvl += 1
		length = len(curs)
		for i in range(length):
			if curs[0].left is not None:
				curs.append(curs[0].left)
			if curs[0].right is not None:
				curs.append(curs[0].right)
			if lvl % swap_level == 0:
				tmp = curs[0].left
				curs[0].left = curs[0].right
				curs[0].right = tmp
			curs.pop(0)	


def init():
	num_nodes = int(raw_input())
	root = Node(1)
	curs = [root]
	while len(curs) > 0:
		length = len(curs)
		for i in range(length):
			line = raw_input().split()
			left_node = int(line[0])
			right_node = int(line[1])
			if left_node > -1: 
				curs[0].left = Node(left_node)
				curs.append(curs[0].left)
			if right_node > -1:
				curs[0].right = Node(right_node)
				curs.append(curs[0].right)
			curs.pop(0)
	num_swaps = int(raw_input())
	for i in range(num_swaps):
		swap_level = int(raw_input())
		do_swap(root, swap_level)
		inOrderWithoutRecursion(root)
		print ''

init()