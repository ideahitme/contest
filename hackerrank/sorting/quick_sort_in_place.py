import sys

def swap(array, i, j):
	tmp = array[i]
	array[i] = array[j]
	array[j] = tmp

def print_inline(x):
	print x,

def quick_sort(array, start, end):
	if start < end:
		pivot = partition(array, start, end)
		[print_inline(el) for el in array]
		print ''
		quick_sort(array, start, pivot-1)
		quick_sort(array, pivot+1, end)

def partition(array, start, to):
	pivot = array[to]
	i = start
	for j in range(i, to):
		if array[j] <= pivot:
			swap(array, i, j)
			i += 1
	swap(array, i, to)
	return i

num_elements = int(raw_input())
array = [int(el) for el in raw_input().split()]
quick_sort(array, 0, len(array)-1)
