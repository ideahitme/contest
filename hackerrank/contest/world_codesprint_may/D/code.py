from random import randint

def solution(numbers):
	total = 0
	by_xor_table = [[0 for _ in xrange(numbers[2]+1)] for _ in xrange(4096)]
	for y in xrange(numbers[2]+1):
		for z in xrange(y, numbers[3]+1):
			val =  y^z % (4096)
			by_xor_table[val][y] += 1

	by_xor_table_from = [[0 for _ in xrange(numbers[2]+1)] for _ in xrange(4096)]
	for val in xrange(4096):
		_total = 0
		for y in xrange(numbers[2], -1, -1):
			_total += by_xor_table[val][y]
			by_xor_table_from[val][y] = _total

	lookup = [[0 for _ in xrange(numbers[2]+1)] for _ in xrange(4096)]
	for val in xrange(4096):
		for lower in xrange(numbers[2]+1):
			same_xor = by_xor_table_from[val][lower]
			ordered_pairs = (numbers[2]-lower+1)*(numbers[2]-lower+2)/2 + (numbers[3]-numbers[2])*(numbers[2]-lower+1)-same_xor
			lookup[val][lower] = ordered_pairs 
	for w in xrange(1, numbers[0]+1):
		for x in xrange(w, numbers[1]+1):
			val = w^x % (4096)
			total += lookup[val][x]
	return total

numbers = sorted([int(k) for k in raw_input().strip('').split()])

# for i in xrange(20):
# 	for j in xrange(i, 20):
# 		for k in xrange(j, 20):
# 			for l in xrange(k, 20):
print solution(numbers)