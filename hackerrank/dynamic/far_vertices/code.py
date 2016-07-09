import operator 

line = raw_input().strip().split()

def bfs_unreachable(graph, root, k):
	visited, stack = [], [{
		"val": root,
		"dist": 0
	}]
	traversal = []
	while len(stack) > 0:
		vertex = stack.pop(0)
		traversal.append(vertex)
		if vertex not in visited:
			visited.append(vertex["val"])
			for neighbour in graph[vertex["val"]]:
				if neighbour not in visited:
					stack.append({
						"val": neighbour,
						"dist": vertex["dist"] + 1
					})
	unreachable = [vertex["val"] for vertex in traversal if vertex["dist"] > k]
	return map(lambda x: (root, x) if root < x else (x, root), unreachable)

def find_distant_pairs(graph, k):
	distant_pairs = []
	unreachable_lengths = range(len(graph))
	for v in xrange(1, len(graph)):
		unreachable_pairs = bfs_unreachable(graph, v, k)
		unreachable_lengths[v] = len(unreachable_pairs) 
		distant_pairs.append(unreachable_pairs)
	return (list(set(reduce(operator.add, distant_pairs))), unreachable_lengths)

def solution(graph, k):
	(distant_pairs, unreachable_lengths) = find_distant_pairs(graph, k)
	removed = 0
	if len(distant_pairs) == 0: return 0
	while True:
		removed += 1
		(max_index, max_value) = max(enumerate(unreachable_lengths), key=operator.itemgetter(1))
		to_be_removed = max_index
		unreachable_lengths[max_index] = 0
		new_distant_pairs = []
		for tpl in distant_pairs:
			if tpl[0] == to_be_removed:
				unreachable_lengths[tpl[1]] -= 1
			elif tpl[1] == to_be_removed:
				unreachable_lengths[tpl[0]] -= 1
			else:
				new_distant_pairs.append(tpl)
		if len(new_distant_pairs) == 0: break
		distant_pairs = new_distant_pairs
	return removed

num_vertices = int(line[0])
k = int(line[1])

graph = [[] for _ in xrange(num_vertices+1)]

for _ in xrange(num_vertices-1):
	line = map(int, raw_input().split())
	graph[line[0]].append(line[1])
	graph[line[1]].append(line[0])

print solution(graph, k)
