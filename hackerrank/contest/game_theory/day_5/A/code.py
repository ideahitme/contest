from sets import Set

def grundy_number(root, parent, edges, num_neighbours):
	all_grundies = []
	if num_neighbours[root] == 0:
		return 0
	if num_neighbours[root] == 1 and root != 0:
		return 0
	if num_neighbours[root] == 1 and root == 0:
		return 1
	else:
		nim_sum = 0
		for index, neighbour in enumerate(edges[root]):
			if index != parent and neighbour > 0:
				val = grundy_number(index, root, edges, num_neighbours)
				nim_sum = nim_sum ^ (1 + val)
		return nim_sum


def solution(edges):
	num_neighbours = [0 for _ in xrange(len(edges))]
	for node in xrange(len(num_neighbours)):
		num_neighbours[node] = sum(edges[node])
	val_for_root = grundy_number(0, -1, edges, num_neighbours)
	if val_for_root > 0:
		return 'Alice'
	else:
		return 'Bob'

num_cases = int(raw_input())

for _ in xrange(num_cases):
	num_nodes = int(raw_input())
	edges = [[0 for _ in xrange(num_nodes)] for _ in xrange(num_nodes)]
	for _ in xrange(num_nodes-1):
		line = raw_input().split()
		A = int(line[0])
		B = int(line[1])
		edges[A-1][B-1] = 1
		edges[B-1][A-1] = 1
	print solution(edges)