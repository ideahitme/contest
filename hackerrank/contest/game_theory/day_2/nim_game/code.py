num_cases = int(raw_input())

for _ in xrange(num_cases):
	num_piles = int(raw_input())
	piles = [int(x) for x in raw_input().split()]
	X = reduce(lambda x, y: x^y, piles)
	if X > 0:
		print 'First'
	else:
		print 'Second'