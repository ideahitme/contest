import sys
import math

def num_primes(N):
	if N < 2: return 0
	numbers = [0 for i in range(0, N+1)]
	numbers[1] = 1
	root = int(math.ceil(math.sqrt(N)))
	primes = 0
	for i in range(2, root+1):
		if numbers[i] > 0: continue
		else:
			j = 2*i
			while j < N + 1:
				numbers[j] = 1
				j += i
	for i in range(1, N+1):
		if numbers[i]==0: primes += 1
	return primes

def num_ways(N):
	max_horizontal = N/4
	if max_horizontal == 0: return 1
	cache = [[0 for i in range(N+1)] for j in range(max_horizontal+1)]
	for i in range(0, N+1):
		cache[0][i] = 1
	for j in range(1, max_horizontal+1):
		for i in range(0, 5):
			cache[j][i] = 1
	for j in range(1, max_horizontal+1):
		cache[j][4*max_horizontal] = 1
		for i in range(1, max_horizontal*4+1):
			cache[j][i] = 0
	for j in range(1, max_horizontal+1):
		for i in range(4*j, N+1):
			cache[j][i] = cache[j-1][i-4] + cache[j][i-1]
	res = 0
	for i in range(max_horizontal+1):
		res += cache[i][N]
	return res

num_cases = int(raw_input())

for i in range(num_cases):
	N = int(raw_input())
	num_of_arranging = num_ways(N)
	print num_primes(num_of_arranging)

