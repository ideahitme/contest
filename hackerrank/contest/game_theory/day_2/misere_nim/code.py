num_cases = int(raw_input())

for _ in xrange(num_cases):
	num_piles = int(raw_input())
	piles = [int(x) for x in raw_input().split()]
	onlyOnes = True
	for pile in piles:
		if pile > 1:
			onlyOnes = False
			break
	if onlyOnes:
		if num_piles % 2 == 1:
			print 'Second'
		else:
			print 'First'
	else:
		X = reduce(lambda x, y: x^y, piles)
		if X > 0:
			print 'First'
		else:
			print 'Second'