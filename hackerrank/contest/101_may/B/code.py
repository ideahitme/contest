import math 

len = int(raw_input())

numbers = [int(k) for k in raw_input().split()]

min_for = [-1 for _ in xrange(len)]
for to_compare in xrange(len):
	min_xor = None
	for with_compare in xrange(len):
		if with_compare != to_compare and (min_xor is None or min_xor < numbers[to_compare]^with_compare):
			min_for[to_compare] = with_compare
	