def solution(N):
	return N

num_cases = int(raw_input())

for _ in xrange(num_cases):
	N = int(raw_input())
	if N % 8 == 0:
		print 'Second'
	else:
		print 'First'
