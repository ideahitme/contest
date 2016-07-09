import math
from sets import Set

def grundy_numbers():
	max_number = int(math.pow(10, 5)) + 1
	grundies = [0 for _ in xrange(max_number+1)]
	for num in xrange(1, max_number+1):
		set = Set()
		if num == 1:
			grundies[num] = 0
		else:
			s = int(math.sqrt(num)) + 1
			for num_in_pile in xrange(1, min(s+1, num)):			
				if num_in_pile == 1:
					set.add(0)
				else:
					if num % num_in_pile == 0:
						factor = num/num_in_pile
						if factor % 2 == 1:
							set.add(grundies[num_in_pile])
						if num_in_pile % 2 == 1:
							set.add(grundies[factor])
			i = 0 
			for el in set:
				if el != i:
					break
				i+=1
			grundies[num] = i
	return grundies
grundies = grundy_numbers()

def solution(towers):
	values = map(lambda x: grundies[x], towers)
	X = reduce(lambda x,y: x^y, values)
	if X > 0:
		return 1
	else:
		return 2			

num_cases = int(raw_input())

for _ in xrange(num_cases):
	num_towers = int(raw_input())
	towers = [int(k) for k in raw_input().split()]
	print solution(towers)