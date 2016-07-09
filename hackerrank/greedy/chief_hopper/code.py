import math 

size = int(raw_input())
numbers = [int(x) for x in raw_input().split()]
divisor = 2
_sum = 0
result = -1

for i in xrange(size):
	_sum += _sum + numbers[i]
	if (_sum-1)//divisor + 1 > result:
		result = (_sum-1)//divisor + 1
	divisor *= 2

print result