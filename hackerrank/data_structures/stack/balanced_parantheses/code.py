import sys

MIRROR = {
	'}': '{',
	')': '(',
	']': '[',
}

def is_sequence_valid(seq):
	stack = []
	valid = True
	for bracket in seq:
		if bracket in '{[(':
			stack.append(bracket)
		elif len(stack) == 0:
			valid = False
			break
		elif MIRROR[bracket] != stack[-1]:
			valid = False
			break
		else: 
			stack.pop()
	if len(stack) > 0: valid = False
	return valid

num_cases = int(raw_input())

for i in range(num_cases):
	sequence = raw_input()
	if is_sequence_valid(sequence):
		print 'YES'
	else: print 'NO'