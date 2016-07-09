import math
from sets import Set
from random import randint

def isPrime(n):
	return n == 2 or n == 3 or n == 5 or n == 7

def num_composites(numbers):
	dim = len(numbers)
	composites_for_row = [[0 for _ in xrange(dim)] for _ in xrange(dim)]
	for top in xrange(dim):
		for left in xrange(dim):
			if left == 0:
				if not isPrime(numbers[top][left]):
					composites_for_row[top][0] = 1
			else:
				if not isPrime(numbers[top][left]):
					composites_for_row[top][left] = composites_for_row[top][left-1] + 1
				else:
					composites_for_row[top][left] = composites_for_row[top][left-1]
	composites_between_rows = [[[[0] for _ in xrange(dim)] for _ in xrange(dim)] for _ in xrange(dim)]
	for top in xrange(dim):
		for bottom in xrange(top, dim):
			for left in xrange(dim):
				if bottom == top:
					composites_between_rows[top][bottom][left] = composites_for_row[top][left]
				else:
					composites_between_rows[top][bottom][left] = composites_between_rows[top][bottom-1][left] + composites_for_row[bottom][left]
	return composites_between_rows

def minNotInSet(set):
	i = 0 
	for el in set:
		if el != i:
			break
		i+=1	
	return i

def grundy_numbers(numbers, comps):
	dim = len(numbers)
	grundy_numbers = [
		[0 for x in xrange(dim) ] for y in xrange(dim)
	]
	for height in xrange(dim):
		for width in xrange(dim):
			local_grundy = [
				[
					0 for x in xrange(dim-width)
				]
				for y in xrange(dim-height)
			]
			for top in xrange(dim - height):
				for left in xrange(dim - width):
					if height == 0 and width == 0:
						local_grundy[top][left] = 0
					else:
						allPrime = True
						if left == 0:
							if comps[top][top+height][left+width] > 0:
								allPrime = False
						else:
							if comps[top][top+height][left+width]-comps[top][top+height][left-1] > 0:
								allPrime = False
						if allPrime:
							local_grundy[top][left] = 0
						else:
							answers = [0 for _ in xrange(2*dim)]
							for j in xrange(width):
								val = grundy_numbers[height][j][top][left]^grundy_numbers[height][width-j-1][top][left+j+1]
								if val < 2*dim: answers[val] += 1
							for i in xrange(height):
								val = grundy_numbers[i][width][top][left]^grundy_numbers[height-i-1][width][top+i+1][left]
								if val < 2*dim: answers[val] += 1
							i = 0
							for index, answer in enumerate(answers):
								if answer == 0:
									i = index
									break
							local_grundy[top][left] = i
			grundy_numbers[height][width] = local_grundy
	return grundy_numbers[dim-1][dim-1][0][0]


def solution(numbers):
	dim = len(numbers)
	if dim == 0 or dim == 1:
		return 'Second'
	comps = num_composites(numbers)	
	if comps[0][dim-1][dim-1] == 0:
		return 'Second'
	answer = grundy_numbers(numbers, comps)
	if answer > 0:
		return 'First'
	else:
		return 'Second'

if __name__ == "__main__":
	num_cases = int(raw_input())

	for _ in xrange(num_cases):
		dim = int(raw_input())
		numbers = []
		for _ in xrange(dim):
			row = [int(x) for x in raw_input().split()]
			numbers.append(row)
		answer = solution(numbers)
		print answer