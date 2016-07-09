import math

def num_divisors(number):
	if number == 1: return 0
	s = int(math.sqrt(number)) + 1
	isComposite = False
	divisor = 1
	for _ in xrange(2, s+1):
		if number % _ == 0:
			isComposite = True
			divisor = _
			break
	if not isComposite: return 1
	else:
		new_val = int(number/divisor)
		return 1 + num_divisors(new_val)

def solution(N, M):
	if M == 1:
		return 2		
	else:
		heap_size = num_divisors(M)
		X = reduce(lambda x,y: x^y, [heap_size for _ in xrange(N)])	
		if X > 0: return 1
		else: return 2

num_cases = int(raw_input())

for _ in xrange(num_cases):
	comps = [int(x) for x in raw_input().split()]
	print solution(comps[0], comps[1])
