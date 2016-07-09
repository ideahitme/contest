import sys

num_actions = int(raw_input())

stack = []
maximum_stack = []

while num_actions > 0:
	next_line = raw_input()
	action = int(next_line.split()[0])
	if action == 1:
		num = int(next_line.split()[1])
		stack.append(num)
		if len(maximum_stack) == 0 or num >= maximum_stack[-1]:
			maximum_stack.append(num)
	elif action == 2:
		last_num = stack.pop()
		if maximum_stack[-1] == last_num: 
			maximum_stack.pop()
	elif action == 3:
		print maximum_stack[-1]

	num_actions -= 1

