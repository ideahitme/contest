def traverse(graph, root, m, n):
	visited, stack = [], [root]
	while len(stack) > 0:
		vertex = stack.pop()
		if vertex not in visited:
			visited.append(vertex)
			graph[vertex[0]][vertex[1]]["visited"] = True
			for ne in getNeighbours(vertex,m,n):
				if graph[ne[0]][ne[1]]["value"] == 1 and ne not in visited:
					stack.append(ne)
 	return visited

def getNeighbours(tpl, m, n):
	ne = []
	for i in [1,0,-1]:
		for j in [1,0,-1]:
			if i != 0 or j != 0:
				if tpl[0] + i >= 0 and tpl[0] + i <= m-1 and tpl[1] + j >= 0 and tpl[1] + j <= n-1:
					ne.append((tpl[0]+i,tpl[1]+j))
	return ne

m = int(raw_input())
n = int(raw_input())

graph = []

for _ in xrange(m):
	graph.append([{"value":int(x), "visited": False} for x in raw_input().split()])

_max = 0
for i in xrange(m):
	for j in xrange(n):
		if not graph[i][j]["visited"] and graph[i][j]["value"] == 1:
			connected_set = traverse(graph, (i,j), m, n)
			if _max < len(connected_set):
				_max = len(connected_set)

print _max