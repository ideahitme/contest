num_sticks = int(raw_input())

sticks = sorted([int(k) for k in raw_input().split()])


best = 0
result = None

for biggest in xrange(num_sticks-1, 1,-1):
	optimal = 0
	res = None
	for medium in xrange(biggest-1, 0, -1):
		at_least = sticks[biggest]-sticks[medium]
		for smallest in xrange(medium-1,-1,-1):
			if sticks[smallest] > at_least and optimal < (sticks[biggest]+sticks[medium]+sticks[smallest]):
				optimal = sticks[biggest]+sticks[medium]+sticks[smallest]
				res = (sticks[smallest],sticks[medium],sticks[biggest])
	if best < optimal:
		best = optimal
		result = res

if best == 0:
	print -1
else:
	print result[0], result[1], result[2]

		

