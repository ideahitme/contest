def is_possible(numbers):
	size = len(numbers)
	count = [0 for _ in xrange(size)]
	for index, number in enumerate(numbers):
		if index >= 1:
			for sub_index in xrange(index):
				if numbers[sub_index] > numbers[index]:
					count[index] += 1
	total = sum(count)
	return "YES" if total % 2 == 0 else "NO"

num_cases = int(raw_input())

for _ in xrange(num_cases):
	size = int(raw_input())
	numbers = [int(x) for x in raw_input().split()]
	print is_possible(numbers)
