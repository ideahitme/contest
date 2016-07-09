l1 = raw_input().split()

rows = int(l1[0])
cols = int(l1[1])
oprs = int(l1[2])

shifts = [[[y, x] for x in xrange(cols)] for y in xrange(rows)]
answer = [[0 for x in xrange(cols)] for _ in xrange(rows)]

for _ in xrange(oprs):
	l = raw_input().split()
	t = int(l[0])
	if t == 1:
		row = int(l[1])-1 
		tmp = [shifts[row][0][0], shifts[row][0][1]]
		for j in xrange(cols-1):
			shifts[row][j][1] = shifts[row][j+1][1]
			shifts[row][j][0] = shifts[row][j+1][0]
		shifts[row][cols-1] = tmp
	elif t == 2:
		col = int(l[1])-1
		tmp = [shifts[0][col][0], shifts[0][col][1]]
		for i in xrange(rows-1):
			shifts[i][col][0] = shifts[i+1][col][0]
			shifts[i][col][1] = shifts[i+1][col][1]
		shifts[rows-1][col] = tmp
	elif t == 3:
		row = int(l[1])-1
		col = int(l[2])-1
		val = int(l[3])
		answer[shifts[row][col][0]][shifts[row][col][1]] =  val

for i in xrange(rows):
	for j in xrange(cols):
		print answer[i][j],
	print ''
