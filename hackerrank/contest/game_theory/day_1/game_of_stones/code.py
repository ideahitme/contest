def solution(num_stones):
	dp = ['Second' for _ in xrange(num_stones+1)]
	for stones in xrange(num_stones+1):
		if stones < 2:
			dp[stones] = 'Second'
		elif stones == 2 or stones == 3 or stones == 4 or stones == 5: 
			dp[stones] = 'First'
		else:
			if dp[stones-2] == 'Second' or dp[stones-3] == 'Second' or dp[stones-5] == 'Second':
				dp[stones] = 'First'
			else:
				dp[stones] = 'Second'
	return dp[-1]

	if num_stones < 2: return 'Second'
	else:
		pass


num_cases = int(raw_input())

for _ in xrange(num_cases):
	num_stones = int(raw_input())
	print solution(num_stones)