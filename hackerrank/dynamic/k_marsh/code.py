import sys

def pretty_print_array(array):
	for i in range(len(array)):
		print array[i]

line = raw_input()
height = int(line.split()[0])
width = int(line.split()[1])
cells = [[0 for _ in range(width)] for _ in range(height)]
for i in range(height):
	vals = list(raw_input())
	for j in range(width):
		cells[i][j] = 1 if vals[j] == "x" else 0

ups = [[0 for _ in range(width)] for _ in range(height)]

for j in range(width):
	for i in range(height):
		if i == 0: 
			if cells[i][j] == 1:
				ups[i][j] = -1
			else:
				ups[i][j] = 0
		else: 
			if cells[i][j] == 1: 
				ups[i][j] = -1
			else:
				ups[i][j] = ups[i-1][j] + 1

lefts = [[0 for _ in range(width)] for _ in range(height)]
for i in range(height):
	for j in range(width):
		if j == 0: 
			if cells[i][j] == 1: 
				lefts[i][j] = -1
			else:
				lefts[i][j] = 0
		else: 
			if cells[i][j] == 1: 
				lefts[i][j] = -1
			else:
				lefts[i][j] = lefts[i][j-1] + 1

max_col_dist_for_row = [0 for _ in range(height)]

for i in xrange(height):
	max_col_dist_for_row[i] = max([el for el in lefts[i]])

def areColumnsConnectingRows(i, j, left, right):
	return lefts[i][right] >= right-left and lefts[j][right] >= right-left

_max = 0
for i in xrange(height-1):
	for j in xrange(height-1, i, -1):  
		if _max >= 2*(j-i)+2*(min(max_col_dist_for_row[i], max_col_dist_for_row[j])): break
		possible_columns = []
		for k in xrange(width):
			if ups[j][k] >= j-i: possible_columns.append(k)
		if len(possible_columns) < 2: continue
		if _max >= 2*(j-i)+2*(possible_columns[-1]-possible_columns[0]): continue 
		left_pivot = 0
		right_pivot = 1
		max_col_dist = 0
		while right_pivot < len(possible_columns):
			if areColumnsConnectingRows(i, j, possible_columns[left_pivot], possible_columns[right_pivot]):
				if max_col_dist < possible_columns[right_pivot] - possible_columns[left_pivot]:
					max_col_dist = possible_columns[right_pivot] - possible_columns[left_pivot]
				right_pivot += 1
			else: 
				left_pivot += 1
				if left_pivot == right_pivot:
					right_pivot += 1
		if _max < 2*(j-i) + 2*max_col_dist and max_col_dist > 0:
			_max = 2*(j-i) + 2*max_col_dist

if _max == 0: print "impossible"
else: print _max

