import sys

line_one = raw_input()
size = int(line_one.split()[0])
num_operations = int(line_one.split()[1])

change_at_step = [0 for _ in xrange(size+2)]

for _ in xrange(num_operations):
	line = raw_input()
	k = int(line.split()[2])
	start = int(line.split()[0])
	change_at_step[int(line.split()[0])] += k
	change_at_step[int(line.split()[1])+1] -= k

_max = 0
val = 0

for change in change_at_step:
	val += change
	if _max < val:
		_max = val

print _max