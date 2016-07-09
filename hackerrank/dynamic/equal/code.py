import sys

num_cases = int(raw_input())

def equalize(a,b): #a < b
	diff = b-a
	if b == a: return (a, 0)
	by_5 = diff/5
	if diff % 5 == 0:
		return (a, by_5)
	if diff % 5 == 1:
		return (a, 1 + by_5)
	if diff % 5 == 2:
		return (a, 1 + by_5)
	if diff % 5 == 3:
		return (a, 2 + by_5)
	if diff % 5 == 4:
		return (a, 2 + by_5)

def variation(prev):
	total = prev[1]
	for i in xrange(2, len(chocolates)):
		prev = equalize(prev[0], chocolates[i])
		total += prev[1]
	return total


def solution(chocolates):
	prev = None
	total = 0
	diff = chocolates[1] - chocolates[0] 
	if diff % 5 == 4:
		by_5 = diff/5
		return min(variation((chocolates[0]-1, 2 + by_5 )), variation((chocolates[0], 2 + by_5 )))
	if diff % 5 == 3:
		by_5 = diff/5
		return min(variation((chocolates[0]-2, 2 + by_5)), variation((chocolates[0], 2 + by_5 )))
	else:
		prev = equalize(chocolates[0], chocolates[1])
		return variation(prev)

for _ in xrange(num_cases):
	num_people = int(raw_input())
	chocolates = [int(x) for x in raw_input().split()]
	chocolates.sort()
	print solution(chocolates)