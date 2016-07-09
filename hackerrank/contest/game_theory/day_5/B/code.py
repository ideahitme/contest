import math
import pprint 

pp = pprint.PrettyPrinter(indent=4)

def iterator():
	price_per_height = [0 for _ in xrange(200)]
	price_per_height[0] = 1
	price_per_height[1] = None
	price_per_height[2] = None
	price_per_height[3] = 1
	price_per_height[4] = 1
	price_per_height[5] = 2
	price_per_height[6] = 3
	price_per_height[7] = 4
	price_per_height[8] = 5
	price_per_height[9] = 7
	for i in xrange(10,200):
		sqrt = int(math.sqrt(i))
		total = price_per_height[i-1] 
		for diff in xrange(1, sqrt+1):
			k_th_stack = i - diff*diff
			if k_th_stack > 3:
				total += price_per_height[k_th_stack] - price_per_height[k_th_stack-1]
			if i == diff*diff + 1:
				total += 1
		price_per_height[i] = total
	return price_per_height

price_per_height = iterator()
# pp.pprint(price_per_height[:17])

def solution2(height):
	result = 0
	for index, h in enumerate(price_per_height):
		# print index, h
		if height > h:
			result = index
		else:
			break
	return result	

def solution(height):

	dp = [None for _ in xrange(height+1)]
	stacks = []
	for i in xrange(2, height+1):
		if i == 2:
			dp[i] = 4
			stacks = [1,1]
		elif i == 3:
			dp[i] = 5
			stacks = [2,1]
		else:
			# print i-1, stacks, dp[i-1]
			candidate = dp[i-1]
			num_stacks = len(stacks)
			next_candidate = None
			val = None
			for index in xrange(num_stacks):
				stack = stacks[index]
				if next_candidate >= dp[stack+1] + (index+1)*(index+1) or next_candidate is None:
					next_candidate = dp[stack+1] + (index+1)*(index+1)
					val = index
			if next_candidate == candidate:
				stacks[val] += 1
				dp[i] = candidate
			elif next_candidate <= (num_stacks+1)*(num_stacks+1):
				stacks[val] += 1
				dp[i] = next_candidate
			else:
				stacks.append(1)
				dp[i] = (num_stacks+1)*(num_stacks+1)
	# compare = 4
	# for index, val in enumerate(dp):
	# 	if val == compare:
	# 		print index-1, compare
	# 		compare += 1
	# val = iterator()
	# pp.pprint(val[:15])

	return dp[-1]

# for x in xrange(2, 500):
# 	a1 = solution(x)
# 	a2 = solution2(x)
# 	print a1, a2, x
num_cases = int(raw_input())

for _ in xrange(num_cases):
	height = int(raw_input())
	print solution2(height)

