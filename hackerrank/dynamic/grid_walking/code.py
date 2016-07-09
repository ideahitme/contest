import sys
import math

mod_val = 1000000007
def calc_simple(D, total_moves):
	result = [[0 for i in range(total_moves+1)] for j in range(D+1)] 
	for x in range(1, D+1):
		if x == 1 or x == D:
			result[x][1] = 1
		else: result[x][1] = 2
	if D == 1: return [[0 for i in range(total_moves+1)] for j in range(D+1)]
	for moves_available in range(2, total_moves+1):
		for x in range(1, D+1):
			if x == 1: 
				result[x][moves_available] = result[x+1][moves_available-1]
			elif x == D: 
				result[x][moves_available] = result[x-1][moves_available-1]
			else:
				result[x][moves_available] = (result[x-1][moves_available-1] + result[x+1][moves_available-1] ) % mod_val
	return result


def binary_simple(N):
	result = [0 for i in range(N+1)]
	if N == 0: return [1]
	for i in range(0, N+1):
		if i == 0: result[i] = 1
		elif i == 1: result[i] = N
		else: result[i] = ((result[i-1]*(N-i+1))/i)
	return result

def solution(starting_positions, dimensions, M):
	binaries = [binary_simple(i) for i in range(M+1)]
	pre_calc = [[1 for j in range(M+1)] for i in range(len(dimensions))]
	for i in range(len(dimensions)):
		simple = calc_simple(dimensions[i], M)
		for j in range(1, M+1):
			pre_calc[i][j] = simple[starting_positions[i]][j]
	final = [[1 for j in range(M+1)] for i in range(len(dimensions))]
	for j in range(0, M+1):
		final[0][j] = pre_calc[0][j]
	for j in range(1, M+1):
		for i in range(1, len(dimensions)):
			val = 0
			for k in range(j+1):
				val += (final[i-1][j-k]*binaries[j][k]*pre_calc[i][k] ) % mod_val
			final[i][j] = val % mod_val
	return final[-1][-1] % mod_val

num_cases = int(sys.stdin.readline().split()[0])

for i in range(num_cases):
	line = sys.stdin.readline().split()
	num_dimensions = int(line[0])
	M = int(line[1])
	starting_positions = [int(pos) for pos in sys.stdin.readline().split()]
	dimensions = [int(dim) for dim in sys.stdin.readline().split()]
	print solution(starting_positions, dimensions, M)
