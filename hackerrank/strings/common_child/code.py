A = [ord(x)-65 for x in list(raw_input().strip())]
B = [ord(x)-65 for x in list(raw_input().strip())]

next_left_occurence = [[-1 for _ in xrange(len(B))] for _ in xrange(26)]

for char in xrange(26):
	for i in xrange(len(B)):
		if B[i] == char:
			next_left_occurence[char][i] = i
		else:
			next_left_occurence[char][i] = -1 if i == 0 else next_left_occurence[char][i-1]

occ = [[-1 for _ in xrange(len(B)+1)] for _ in xrange(26)]

for char in xrange(26):
	i = len(B)-1
	while i > -1:
		if B[i] == char:
			occ[char][i] = i
		else: 
			occ[char][i] = occ[char][i+1]
		i -= 1

cur_list = range(len(B))

for i in xrange(len(A)):
	prev_list = cur_list
	cur_list = cur_list[:]
	char = A[i]
	j = 0
	if i > 0 and len(occ[char]) > 0:
		j = occ[char][0]
	stop_inc = False
	while j < len(B):
		if i == 0:
			if next_left_occurence[char][j] > -1:
				cur_list[j] = 1
			else:
				cur_list[j] = 0
		else:
			if next_left_occurence[char][j] > 0:
				case_1 = 1 + prev_list[next_left_occurence[char][j]-1]
				case_2 = prev_list[j]
				if case_1 < case_2:
					cur_list[j] = case_2
					j = occ[char][j+1]
					if j == -1: break
					else: continue
				else:
					cur_list[j] = case_1
			else:
				cur_list[j] = prev_list[j]
		j += 1

print cur_list[-1]
