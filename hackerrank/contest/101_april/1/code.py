import sys

S = raw_input()

stack = []

for letter in S:
	if len(stack) > 0:
		if letter == stack[-1]:
			stack.pop()
		else:
			stack.append(letter)
	else:
		stack.append(letter)

if len(stack) == 0:
	print "Empty String"
else: print ''.join(stack)