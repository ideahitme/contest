import sys

def find_contiguous_max(array):
	max_end = [0]*len(array)
	max_end[0] = array[0]
	if len(array) == 1: return max_end[0]
	result = -10**10
	for i in range(len(array)):
		if max_end[i-1] > 0:
			max_end[i] = max_end[i-1] + array[i]
		else:
			max_end[i] = array[i]
		result = max_end[i] if max_end[i] > result else result
	return result

def find_non_contiguous_max(array):
	max_neg_el = None
	find_sum = 0
	found = False
	for el in array:
		if max_neg_el < el:
			max_neg_el = el
		if el > 0: 
			find_sum += el
			found = True
	if found: return find_sum
	return max_neg_el

num_cases = int(sys.stdin.readline().split()[0])

for x in range(num_cases):
	num_el = sys.stdin.readline().split()[0]
	elements = [int(el) for el in sys.stdin.readline().split()]
	print find_contiguous_max(elements), find_non_contiguous_max(elements)