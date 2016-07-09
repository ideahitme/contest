line = raw_input().split()
height = int(line[0])
time = int(line[1])

tree = [[0.0 for _ in xrange(k+1)] for k in xrange(height)]

def add_to_kids(tree, i, j, val):
	if (i == height-1): return
	else:
		tree[i+1][j] += float(val)/2.0
		tree[i+1][j+1] += float(val)/2.0

while(time > 0):
	for i in xrange(height):
		if i == 0:
			tree[0][0] += 1
			if (tree[0][0] > 1):
				add_to_kids(tree, 0, 0, (tree[0][0]-1))
				tree[0][0] = 1
		else:
			for j in xrange(i+1):
				if tree[i][j] > 1:
					add_to_kids(tree, i, j, (tree[i][j]-1))
					tree[i][j] = 1
	time -= 1

total = 0
for i in xrange(height):
	for j in xrange(i+1):
		if tree[i][j] == 1.0:
			total += 1

print total