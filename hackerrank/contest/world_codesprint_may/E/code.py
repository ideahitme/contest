import math

def lookup(l, R, cur_level, cur_block):
	print cur_level, cur_block


def solution(L, R):
	#find starting position of L
	#1st level [1, 10], [11, 20],..,[91, 100]
	representation = []
	index = 1
	while True:
		if len(L) < index:
			representation.insert(0, L)
			break
		else:
			representation.insert(0, L[-index:])
			L = L[:-index]
			index = index*2
	print representation
	pass

L = list(raw_input())
R = list(raw_input())

print solution(L, R)
