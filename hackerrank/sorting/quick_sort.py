import sys

def print_inline(x):
	print x,
def quick_sort(array):
	if len(array) == 0: return []
	if len(array) == 1: return [array[0]]
	left, right, equal = [], [], []
	pivot = array[0]
	for i in range(len(array)):
		if array[i] < pivot: left.append(array[i])
		elif array[i] > pivot: right.append(array[i])
		else: equal.append(array[i])
	_sorted = quick_sort(left) + equal + quick_sort(right)
	return _sorted


num_elements = int(raw_input())
array = [int(el) for el in raw_input().split()]
print quick_sort(array)
