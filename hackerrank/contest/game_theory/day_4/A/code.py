import math

def solution(A, B):
	n = len(A)
	C = [(A[i], B[i], A[i]+B[i]) for i in xrange(n)]
	C.sort(key=lambda x: -x[2])
	def compare(c1, c2):
		if c1[1][2] > c2[1][2]: return -1
		elif c1[1][2] < c2[1][2]: return 1
		else:
			if c1[0] % 2 == 0:
				return c1[1][0] - c2[1][0]
			else:
				return c1[1][1] - c2[1][1]
	C = sorted(enumerate(C), cmp=compare)
	_a = 0
	_b = 0
	for _ in xrange(n):
		if _ % 2 == 0:
			_a += C[_][1][0]
		else:
			_b += C[_][1][1]
	if _a > _b:
		return 'First'
	elif _a < _b:
		return 'Second'
	else:
		return 'Tie'

num_cases = int(raw_input())

for _ in xrange(num_cases):
	n = int(raw_input())
	A = [int(a) for a in raw_input().split()]	
	B = [int(b) for b in raw_input().split()]
	print solution(A, B)
