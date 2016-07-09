def merge_sort(array):
	if len(array) == 1: 
		return (array, 0)
	elif len(array) == 2:
		if array[0] < array[1]:
			return (array, 0)
		else: 
			return ([array[1], array[0]], 1)
	else:
		midpoint = len(array)/2
		first_sorted, count_1 = merge_sort(array[:midpoint])
		second_sorted, count_2 = merge_sort(array[midpoint:])
		_sorted = []
		pivot_1 = 0
		pivot_2 = 0
		count = 0
		while True:
			if len(first_sorted) == 0:
				_sorted += second_sorted
				break
			if len(second_sorted) == 0:
				_sorted += first_sorted
				break
			if first_sorted[0] < second_sorted[0]:
				_sorted.append(first_sorted[0])
				first_sorted.pop(0)
			else:
				_sorted.append(second_sorted[0])
				second_sorted.pop(0)
				count += len(first_sorted)

		return (_sorted, count+count_1+count_2)

def solution(position):
	valid = True
	shifts = [0 for _ in xrange(len(position))]
	for index, pos in enumerate(position):
		shifts[index] = pos - index - 1
		if pos - index - 1 > 2:
			valid = False
 			break 
	if not valid:
		return False
	else:
		check_ = 0
		lefts = 0
		for _ in xrange(len(shifts)):
			check_ += shifts[_]
			if check_ < 0:
				valid = False
				break
			if shifts[_] > 0: lefts += shifts[_]
		if not valid:
			return False
		else:
			sort, val = merge_sort(position)			
			return val


num_cases = int(raw_input())

for _ in xrange(num_cases):
	size = int(raw_input())
	position = [int(x) for x in raw_input().split()]
	answer = solution(position)
	if type(answer) is int:
		print answer
	else: print "Too chaotic"