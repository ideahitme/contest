import sys
import math

num_cases = int(raw_input())
mod_val = int(math.pow(10, 9)+7)
def solution(left, right):
	_left = 1
	_right = 1 
	_sum = 0
	while(True):
		if len(left) + len(right) == 0: break
		elif len(left) == 0:
			_sum += _left * right.pop()
		elif len(right) == 0:
			_sum += _right * left.pop()
		else:
			if left[-1] > right[-1]:
				_sum += _right * left.pop()
				_left += 1
			else:
				_sum += _left * right.pop()
				_right += 1
	return _sum % mod_val

for i in range(num_cases):
	first_line = sys.stdin.readline()
	m = int(first_line.split()[0])	
	n = int(first_line.split()[1])
	left = [int(num) for num in sys.stdin.readline().split()]	
	right = [int(num) for num in sys.stdin.readline().split()]
	left.sort()
	right.sort()
	print solution(left, right)
	