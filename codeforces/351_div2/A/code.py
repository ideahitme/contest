position = int(raw_input())

if position < 10:
	print position
elif position < 190:
	remainder = (position + 1) % 2
	which = (position - 9)/2 + 9 + remainder
	if position % 2 == 0:
		print which/10
	else:
		print which % 10
else:
	which = (position - 190)/3 + 100
	str_which = str(which)
	if position % 3 == 0:
		print str_which[2]
	elif position % 3 == 1:
		print str_which[0]
	elif position % 3 == 2:
		print str_which[1]
