def calc_suffix_sum(numbers):
	suffix = [numbers[-1]]
	for el in reversed(numbers[:-1]):
		suffix.append(suffix[-1]+el)
	return suffix

def solution(numbers, suffix_sum):
	dp = [0]
	for i in xrange(1, len(numbers)+1):
		if i <= 3:
			dp.append(reduce(lambda x,y: x+y, numbers[-i:]))
		else:
			candidates = [
				numbers[-i] + (suffix_sum[i-2] - dp[i-1]),
				numbers[-i] + numbers[ -i + 1] + (suffix_sum[i-3] - dp[i-2]),
				numbers[-i] + numbers[ -i + 1] + numbers[ -i + 2] + (suffix_sum[i-4] - dp[i-3])
			]
			dp.append(max(candidates))
	return dp[-1]			
	
num_cases = int(raw_input())

for _ in xrange(num_cases):
	num_bricks = int(raw_input())
	numbers = [int(x) for x in raw_input().split()]
	suffix_sum = calc_suffix_sum(numbers)
	print solution(numbers, suffix_sum)
