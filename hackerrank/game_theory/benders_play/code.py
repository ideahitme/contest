def find_grundy(edges, cache, start):
	if cache[start] > -1:
		return cache[start]
	if len(edges[start]) == 0:
		return 0
	else:
		values = [0 for _ in xrange(1000)]
		for neighbour in edges[start]:
			g = find_grundy(edges, cache, neighbour)
			values[g] += 1
		answer = 0
		for _ in xrange(len(values)):
			if values[_] == 0:
				answer = _
				break
		cache[start] = answer
		return answer

line = raw_input().split()

num_vertices = int(line[0])
num_edges = int(line[1])

edges = [[] for _ in xrange(num_vertices)]

for _ in xrange(num_edges):
	line = raw_input().split()
	A = int(line[0]) - 1
	B = int(line[1]) - 1
	edges[A].append(B)

num_cases = int(raw_input())

grundy_numbers = [-1 for _ in xrange(num_vertices)]
cache = [-1 for _ in xrange(num_vertices)]
for vertex in xrange(len(grundy_numbers)):
	grundy_numbers[vertex] = find_grundy(edges, cache, vertex)

for case in xrange(num_cases):
	num_soldires = int(raw_input())
	val = 0
	for el in raw_input().split():
		v = int(el)
		val = val ^ grundy_numbers[v-1]
	if val > 0:
		print 'Bumi'
	else:
		print 'Iroh'
