import math

modulo = math.pow(10, 9) + 7

catalans = []
for i in xrange(10000):
	if i == 0:
		catalans.append(1)
	else:
		catalans.append(int((2*(2*i-1)*catalans[-1])/(i+1) % modulo))

factorials = []
for i in xrange(10000):
	if i == 0:
		factorials.append(1)
	else:
		factorials.append(int(i*factorials[-1] % modulo))


def solution(X, Y):
	dp = [[None for _ in xrange(Y+1)] for _ in xrange(X+1)]
	helper = [[0 for _ in xrange(Y+1)] for _ in xrange(X+1)]
	for i in xrange(X+1):
		for j in xrange(Y+1):
			if i == j and i == 0:
				helper[i][j] = 0
				dp[i][j] = 1
			elif i == 0:
				dp[i][j] = catalans[j]
			elif j == 0:
				dp[i][j] = catalans[i]
			else:
				total = 0
				for sj in xrange(j):
					total += int(dp[i][j-sj-1]*catalans[sj] % modulo)
				for si in xrange(i):
					for sj in xrange(j+1):
						total += int(dp[si][sj]*dp[i-si-1][j-sj] % modulo)
				dp[i][j] = int(total % modulo)
	return dp

num_cases = int(raw_input())

for _ in xrange(num_cases):
	line = raw_input().split()
	rounds = []
	squares = []
	rounds.append(int(line[0]))
	squares.append(int(line[1]))
	dp = solution(max(rounds), max(squares))
	for _ in xrange(len(rounds)):
		print int((dp[rounds[_]][squares[_]] * factorials[squares[_]] * factorials[rounds[_]]) % modulo)
# 10160640 