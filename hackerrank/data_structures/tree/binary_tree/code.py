class Node:
	def __init__(self, data=None, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right

def preOrder(root): #traversal
	if root is None: 
		return
	print root.data, 
	if root.left is not None:
		preOrder(root.left)
	if root.right is not None:
		preOrder(root.right)

def postOrder(root):
	if root is None:
		return
	if root.left is not None:
		postOrder(root.left)
	if root.right is not None:
		postOrder(root.right)
	print root.data,

def inOrder(root):
	if root is None:
		return
	if root.left is not None:
		inOrder(root.left)
	print root.data,	
	if root.right is not None:
		inOrder(root.right)

def height(root):
	if root is None:
		return 0
	return max(height(root.left), height(root.right)) + 1

def breadthFirst(root):
	currents = [root]
	while len(currents) > 0:
		length = len(currents)
		for i in range(length):
			print currents[0].data
			if currents[0].left is not None:
				currents.append(currents[0].right)
			if currents[0].right is not None:
				currents.append(currents[0].right)
			currents.pop(0)

