import sys

def merge_sort(array):
	if len(array) == 0: return []
	if len(array) == 1: return [array[0]]
	middle = len(array)/2
	left = merge_sort(array[0:middle])
	right = merge_sort(array[middle:len(array)])
	l_i, r_i = 0, 0
	i = 0
	while l_i < len(left) and r_i < len(right):
		if left[l_i] <= right[r_i]:
			array[i] = left[l_i]
			l_i += 1
		else:
			array[i] = right[r_i]
			r_i += 1
		i += 1
	while l_i < len(left):
		array[i] = left[l_i]
		i += 1
		l_i += 1
	while r_i < len(right):
		array[i] = right[r_i]
		i += 1
		r_i += 1
	return array

num_elements = int(raw_input())
array = [int(el) for el in raw_input().split()]
print merge_sort(array)
