def solution(alice, bob):
	comp = [0, 0]
	for i in xrange(3):
		if alice[i] > bob[i]:
			comp[0] += 1
		if alice[i] < bob[i]:
			comp[1] += 1
	return comp

alice = [int(k) for k in raw_input().split()]
bob = [int(k) for k in raw_input().split()]

print " ".join(map(str, solution(alice, bob)))