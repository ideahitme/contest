def len_of_sequence(height, width):
	return 2*(height-1)+2*(width-1)

def pos_in_sequence(tpl, height, width):
	size = len_of_sequence(height, width)
	i = tpl[0]
	j = tpl[1]
	if j == 1:
		return i - 1
	elif i == height:
		return height-1+j-1
	elif j == width:
		return height-1+width-1+(height-i)
	elif i == 1:
		return size + 1 - j

def generate_sequence(height, width):
	sequence = []
	i = 1
	j = 1
	while i < height:
		sequence.append((i, 1))
		i += 1
	while j < width:
		sequence.append((height, j))
		j += 1
	while i > 1:
		sequence.append((i, width))
		i -= 1
	while j > 1:
		sequence.append((1, j))
		j -= 1
	return sequence

def generate_sequences(M, N):
	sequences = [[]]
	while M > 0 and N > 0:
		seq = generate_sequence(M, N)
		sequences.append(seq)
		M-=2
		N-=2
	return sequences

def which_sequence(i, j, M, N):
	i = i if i < M/2+1 else M-i+1
	j = j if j < N/2+1 else N-j+1
	return min(i, j)

def find_position(sequences,i, j, M, N, R):
	# print (i,j)
	i += 1
	j += 1
	delta = which_sequence(i, j, M, N)
	i -= (delta-1)
	j -= (delta-1)
	# print "delta", delta
	# print (i,j)
	height = M - (delta-1)*2
	width = N - (delta-1)*2
	seq = sequences[delta]
	# print seq
	pos_in_seq = pos_in_sequence((i, j), height, width)
	# print "position", pos_in_seq
	seq_len = len_of_sequence(height, width)
	# print "new position", seq[(pos_in_seq+R)%seq_len]
	return (seq[(pos_in_seq+R)%seq_len][0]+delta-2, seq[(pos_in_seq+R)%seq_len][1]+delta-2)


def solution(M, N, array, R):
	sequences = generate_sequences(M, N)
	new_array = [[0 for _ in xrange(N)] for _ in xrange(M)]
	for i in xrange(M):
		for j in xrange(N):
			(new_i, new_j) = find_position(sequences, i, j, M, N, R)
			new_array[new_i][new_j] = array[i][j]
	for i in xrange(M):
		for j in xrange(N):
			print new_array[i][j],
		print ""

first_line = raw_input().split()

M = int(first_line[0])
N = int(first_line[1])
R = int(first_line[2])
array = []

for _ in xrange(M):
	array.append([int(x) for x in raw_input().split()])
# sequences = generate_sequences(4, 4)
# print find_position(sequences, 0, 1, 4, 4, 2)
solution(M, N, array, R)

# 3 4 8 12
# 2 11 10 16
# 1 7 6 15
# 5 9 13 14