num_days = int(raw_input())

if num_days <= 2:
	print 0, num_days
else:
	remainder_2 = (num_days-2) % 7
	to_add_2 = (remainder_2-5) if remainder_2 >= 5 else 0
	remainder_5 = (num_days-5) % 7
	if remainder_5 == 0:
		to_add_5 = 0
	elif remainder_5 == 1:
		to_add_5 = 1
	else:
		to_add_5 = 2
	min_days = ((num_days-2)/7)*2+2+to_add_2
	max_days = (num_days-5)/7*2 + to_add_5
	print max_days, min_days