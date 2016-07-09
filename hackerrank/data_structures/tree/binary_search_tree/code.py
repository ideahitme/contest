class Node:
	def __init__(self, data=None, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right

def insert(root, value):
	if root is None:
		return Node(value)
	if root.data >= value:
		if root.left is None:
			root.left = Node(value)
		else:
			insert(root.left, value)
	else:
		if root.right is None:
			root.right = Node(value)
		else:
			insert(root.right, value)


def lowest_common_ancestor(root, value1, value2):
	if root.data > value1 and root.data < value2:
		return root
	if root.data < value1 and root.data > value2:
		return root
	if root.data > value1:
		return lowest_common_ancestor(root.left, value1, value2)
	if root.data < value1:
		return lowest_common_ancestor(root.right, value1, value2)