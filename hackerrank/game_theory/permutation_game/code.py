def grundy_number(selection, perm):
	prev = None
	isIncreasing = True
	for index, el in enumerate(perm):
		if selection[index] == 1:
			if prev is None:
				prev = el
			else:
				if prev > el:
					isIncreasing = False
					break
				else:
					prev = el
	# print selection, perm, isIncreasing
	if isIncreasing: 
		return 0
	else:
		answers = [0 for _ in xrange(1000)]
		for index in xrange(len(perm)):
			if selection[index] == 1:
				selection[index] = 0
				val = grundy_number(selection, perm)
				answers[val] += 1
				selection[index] = 1
		final = 0
		for index, el in enumerate(answers):
			if el == 0:
				final = index
				break
		# print selection, perm, isIncreasing, final
		return final
 
def solution(perm, size):
	selection = [1 for _ in xrange(size)]
	if grundy_number(selection, perm) > 0:
		return 'Alice'
	else:
		return 'Bob'

num_cases = int(raw_input())

for _ in xrange(num_cases):
	size = int(raw_input())
	perm = [int(k) for k in raw_input().split()]
	print solution(perm, size)

