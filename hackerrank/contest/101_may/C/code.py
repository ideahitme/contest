line = raw_input().split()

n = int(line[0])
m = int(line[1])

perm = [int(k) for k in raw_input().split()]

if m <= n:


else:
	for _ in xrange(n):
		