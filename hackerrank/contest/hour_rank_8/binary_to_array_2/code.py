num_cases = int(raw_input())

for _ in xrange(num_cases):
	size = int(raw_input())
	bin_array = [int(x) for x in raw_input().split()]
	result = None
	if size == 1:
		result = [1,1,bin_array[0]-1]
	if size == 2:
		if bin_array[0] > 1: result = [1, bin_array[1]+1 , bin_array[0]-1]
	else:
		if size % 2 == 1:
			result = bin_array[:-2] + [bin_array[-2]-1] + [1]  + [1] + [bin_array[-1]-1]
		else: 
			if bin_array[-3] == 1:
				result = bin_array[:-4] + [bin_array[-4]+1] + []
			else:
				result = bin_array[:-3] + [bin_array[-3]-1] + [1] + [bin_array[-1]] + [bin_array[-2]-1]

	print len(result)
	print " ".join(map(str, result))

