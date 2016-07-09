from collections import Counter

def solution(numbers, allowed):
	changes = 0
	total = len(numbers)
	size = len(numbers)/2
	made_changes = [0 for _ in xrange(len(numbers)+1)]
	for i in xrange(size):
		if numbers[i] > numbers[total-i-1]:
			changes += 1
			numbers[total-i-1] = numbers[i]
		elif numbers[i] < numbers[total-i-1]:
			changes += 1
			numbers[i] = numbers[total-i-1]
		made_changes[i+1] = changes
	if changes > allowed:
		return -1
	else:
		permitted = allowed - changes
		for i in xrange(size+1):
			if permitted == 0: break
			if numbers[i] == '9': continue
			if i == total - i - 1:
				permitted -= 1
				numbers[i] = '9'
			else:
				if made_changes[i+1]-made_changes[i] > 0:
					numbers[i] = '9'
					numbers[total-i-1] = '9'
					permitted -= 1
				else:
					if permitted < 2: continue
					else:
						numbers[i] = '9'
						numbers[total-i-1] = '9'
					permitted -= 2
		index = 0
		while True:
			if numbers[index] == '0':
				index += 1
			else:
				break
		return "".join(numbers[index:])

line = raw_input().split()

total_digits = int(line[0])
k = int(line[1])

numbers = list(raw_input().strip())

print solution(numbers, k)