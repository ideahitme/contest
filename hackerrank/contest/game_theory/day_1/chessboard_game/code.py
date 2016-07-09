def build_dp():
	dp = [[0 for _ in xrange(15)] for _ in xrange(15)]
	for _sum in xrange(29):
		x_from = max(0, _sum-14)
		for x in xrange(x_from, 15):
			y = _sum - x
			win = False
			for i in [-1, 1]:
				for j in [-2]:
					if 0 <= x + i <= 14 and 0 <= y+j:
						if dp[x+i][y+j] == 2:
							win = True
					if 0 <= y + i <= 14 and 0 <= x+j:
						if dp[x+j][y+i] == 2:
							win = True
			if not win:
				dp[x][y] = 2
			else:
				dp[x][y] = 1
	return dp

dp = build_dp()


num_cases = int(raw_input())

for i in xrange(num_cases):
	line = raw_input().strip().split()
	x = int(line[0])
	y = int(line[1])
	if dp[x-1][y-1] == 1:
		print 'First'
	else:
		print 'Second'
