import sys

def solution(numbers):
	total = 0
	by_xor_table = [[0 for _ in range(numbers[2]+1)] for _ in range(2*numbers[3]+2)]
	for y in range(1, numbers[2]+1):
		for z in range(y, numbers[3]+1):
			val =  y^z % (2*numbers[3]+2)
			by_xor_table[val][y] += 1

	by_xor_table_from = [[0 for _ in range(numbers[2]+1)] for _ in range(2*numbers[3]+2)]
	for val in range(2*numbers[3]+2):
		_total = 0
		for y in range(numbers[2], 0, -1):
			_total += by_xor_table[val][y]
			by_xor_table_from[val][y] = _total

	lookup = [[0 for _ in range(numbers[2]+1)] for _ in range(2*numbers[3]+2)]
	for val in range(2*numbers[3]+2):
		for lower in range(1, numbers[2]+1):
			same_xor = by_xor_table_from[val][lower]
			ordered_pairs = (numbers[2]-lower+1)*(numbers[2]-lower+2)/2 + (numbers[3]-numbers[2])*(numbers[2]-lower+1)-same_xor
			lookup[val][lower] = ordered_pairs 
	for w in range(1, numbers[0]+1):
		for x in range(w, numbers[1]+1):
			val = w^x % (2*numbers[3]+2)
			total += lookup[val][x]
	return total

for line in sys.stdin:
	numbers = sorted([int(k) for k in line.split()])



# for i in range(1, 20):
# 	for j in range(i, 20):
# 		for k in range(j, 20):
# 			for l in range(k, 20):
print (int(solution(numbers)))