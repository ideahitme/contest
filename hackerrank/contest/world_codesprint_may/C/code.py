def solution(n, k):
	positions = range(n)
	perm = [0 for _ in xrange(n)]
	counters = [1 for _ in xrange(n)]
	for pos in positions:
		if pos-k >= 0 and counters[pos-k] != 0:
			perm[pos] = pos-k+1
			counters[pos-k] = 0
		elif pos+k <= n-1 and counters[pos+k] != 0:
			counters[pos+k] = 0
			perm[pos] = pos+k+1
		else:
			break
	if sum(counters) > 0:
		return -1
	return " ".join(map(str, perm))

num_cases = int(raw_input())

for _ in xrange(num_cases):
	line = raw_input().split()
	n = int(line[0])
	k = int(line[1])
	print solution(n, k)