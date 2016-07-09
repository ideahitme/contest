from collections import Counter

def solution(stones):
	pass

num_cases = int(raw_input())

for case in xrange(num_cases):
	num_stones = int(raw_input())
	stones = [int(k) for k in raw_input().split()]
	cnt = Counter(stones)
	print solution(stones)