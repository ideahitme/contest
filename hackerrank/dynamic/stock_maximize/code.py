import sys

def solution(prices):
	res = 0
	max_in_future = get_max_in_future(prices)
	for i in range(len(prices)):
		if prices[i] < max_in_future[i]:
			res += max_in_future[i] - prices[i]
	return res

def get_max_in_future(prices): #max_in_future[i] - max value in array from i to last el
	max_so_far = prices[-1]
	max_in_future = [0 for i in range(len(prices))]
	for i in range(len(prices)-1, -1, -1):
		if max_so_far <= prices[i]:
			max_so_far = prices[i]
		max_in_future[i] = max_so_far
	return max_in_future


num_tests = int(sys.stdin.readline().split()[0])

for i in range(num_tests):
	num_days = int(sys.stdin.readline().split()[0])
	prices = [int(price) for price in sys.stdin.readline().split()]
	print solution(prices)

