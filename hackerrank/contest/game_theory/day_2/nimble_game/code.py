num_cases = int(raw_input())

for _ in xrange(num_cases):
	num_squares = int(raw_input())
	squares = [int(x) for x in raw_input().split()]
	piles = []
	X = 0
	for index, square in enumerate(squares):
		if index > 0:
			if square > 0:
				if square % 2 == 0:
					new_X = 0
				else:
					new_X = index
				X = X^new_X
	if X > 0:
		print 'First'
	else:
		print 'Second'