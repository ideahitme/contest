import sys

modulo = pow(10, 9) + 7


def solution(N, M):
	

num_cases = int(raw_input())

for _ in xrange(num_cases):
	next_line = raw_input()
	num_letters = int(next_line.split()[0])
	word_length = int(next_line.split()[1])
	print solution(num_letters, word_length)


# 1550477
# 5842
# 170625
# 2781184
# 15346786

# 1734048
# 8704
# 294912
# 2235648
# 32342016
