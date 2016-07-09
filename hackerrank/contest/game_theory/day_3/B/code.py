import pprint
from sets import Set
pp = pprint.PrettyPrinter(indent=4)
def grundy_numbers():
	dp = [[0 for _ in xrange(15)] for _ in xrange(15)]
	for _sum in xrange(29):
		x_from = max(0, _sum-14)
		for x in xrange(x_from, 15):
			y = _sum - x
			win = False
			set = Set()
			for i in [-1, 1]:
				for j in [-2]:
					if 0 <= x + i <= 14 and 0 <= y+j:
						set.add(dp[x+i][y+j])
					if 0 <= y + i <= 14 and 0 <= x+j:
						set.add(dp[x+j][y+i])
			i = 0 
			for el in set:
				if el != i:
					break
				i+=1	
			dp[x][y] = i
	return dp

grundies = grundy_numbers()

# pp.pprint(grundies)

def solution(positions):
	heaps = []
	for pos in positions:
		heaps.append(grundies[pos[0]-1][pos[1]-1])
	X = reduce(lambda x,y: x^y, heaps)
	if X > 0:
		return 'First'
	else:
		return 'Second'

num_cases = int(raw_input())

for _ in xrange(num_cases):
	num_pos = int(raw_input())
	positions = []
	for _ in xrange(num_pos):
		line = map(int, raw_input().split())
		positions.append([line[0], line[1]])
	if len(positions) == 0:
		print 'Second'
	else: print solution(positions)
