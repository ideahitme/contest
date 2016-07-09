import sys
import math 

line = sys.stdin.readline().split()
P = None
Q = None
if len(line) == 1:
	P = float(line[0])
	Q = float(sys.stdin.readline().split()[0])
else:
	P = float(line[0])
	Q = float(line[1])

i = 1
def when_pass(pivot):
	return math.ceil(pivot*100/Q)

result = None
while True:
	pivot = when_pass(i)
	if Q*float(pivot)/float(100) - i < 0.000001:
		limit = i-1
	else: limit = i
	if pivot*P/100 < limit: 
		result = pivot
		break
	if limit == i-1:
		if (pivot+1)*P < i*100:
			result = pivot+1
			break
	i += 1

print int(result)