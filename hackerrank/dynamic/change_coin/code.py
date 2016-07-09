import sys
import math 

numbers = sys.stdin.readline().split()
N = int(numbers[0])
M = int(numbers[1])

coins = [int(el) for el in sys.stdin.readline().split()]
coins.sort()

num_ways = [[0 for i in range(N+1)]for j in coins]
for i in range(len(coins)):
	for j in range(0, N+1):
		if i == 0 and j % coins[0] == 0: 
			num_ways[i][j] = 1
 		elif i == 0: 
 			num_ways[i][j] = 0
		else:
			if (j >= coins[i]): num_ways[i][j] = num_ways[i-1][j] + num_ways[i][j-coins[i]]
			if (j < coins[i]): num_ways[i][j] = num_ways[i-1][j]


print num_ways[M-1][N]

