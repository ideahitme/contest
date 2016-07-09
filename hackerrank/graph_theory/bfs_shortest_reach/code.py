import sys

def _print(x):
	print x,

def bfs(graph, start, shortest):
	visited, stack = [], [start]
	shortest[start] = 0
	x = 6
	while len(stack) > 0:
		vertex = stack.pop(0)
		if vertex not in visited:
			visited.append(vertex)
			for neighbour in graph[vertex]:
				if neighbour not in visited:
					shortest[neighbour] = (shortest[vertex] + x) if shortest[neighbour] == -1 else shortest[neighbour]
					stack.append(neighbour)

def solution(graph, start):
	result = [-1 for i in range(len(graph))]
	bfs(graph, start, result)
	[_print(_) for (index, _) in enumerate(result) if index != start and index > 0]
	print ""
num_cases = int(raw_input())
for i in xrange(num_cases):
	line = raw_input()
	num_vertices = int(line.split()[0])
	num_edges = int(line.split()[1])
	graph = [[] for _ in xrange(num_vertices + 1)]
	for _ in xrange(num_edges):
		line = raw_input()
		x = int(line.split()[0])
		y = int(line.split()[1])
		graph[x].append(y)
		graph[y].append(x)
	start_point = int(raw_input())
	solution(graph, start_point)