import sys

graph = {
	'A': frozenset(['B', 'C', 'D']),
	'B': frozenset(['A', 'E', 'F']),
	'C': frozenset(['A', 'G', 'H', 'I']),
	'D': frozenset(['A', 'J', 'K']),
	'E': frozenset(['B']),
	'F': frozenset(['B']),
	'G': frozenset(['C']),
	'H': frozenset(['C']),
	'I': frozenset(['C']),
	'J': frozenset(['D']),
	'K': frozenset(['D', 'L', 'M']),
	'L': frozenset(['K', 'M']),
	'M': frozenset(['K', 'L'])
}

# graph = {'A': ['B', 'C'],
#          'B': ['A', 'D', 'E'],
#          'C': ['A', 'F'],
#          'D': ['B'],
#          'E': ['B', 'F'],
#          'F': ['C', 'E']}

def dfs(graph, start):
    visited, stack = [], [start]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.append(vertex)
            stack.extend([x for x in graph[vertex] if x not in visited])
    return visited


def bfs(graph, start):
    visited, stack = [], [start]
    while stack:
        vertex = stack.pop(0)
        if vertex not in visited:
            visited.append(vertex)
            stack.extend([x for x in graph[vertex] if x not in visited])
    return visited

print dfs(graph, 'A')
print bfs(graph, 'A')

def dfs_path(graph, root, goal, path=None):
	if path is None:
		path = [root]
	if root == goal:
		yield path
	for vertex in [x for x in graph[root] if x not in path]:
		for each_path in dfs_path(graph, vertex, goal, path + [vertex]):
			yield each_path

print list(dfs_path(graph, 'A', 'M'))


