import math

raw = raw_input().strip()
word = list(raw)
size = len(word)

sorted_index = sorted(range(size), key=lambda x: word[x]) 

rank = 0
ranks = []
prev = word[sorted_index[0]]
for el in sorted_index:
	if word[el] != prev:
		prev = word[el]
		rank += 1
	ranks.append((rank, el))

suffix_to_rank = [ 0 for _ in xrange(size) ]
for el in ranks:
	suffix_to_rank[el[1]]= el

log_2 = int(math.log(size, 2)) + 1

for power in xrange(log_2):
	val_of_two = pow(2, power)
	def compare(x,y):
		if suffix_to_rank[x][0] < suffix_to_rank[y][0]: return -1
		elif suffix_to_rank[x][0] > suffix_to_rank[y][0]: return 1
		else:
			if x + val_of_two >= size: return -1
			if y + val_of_two >= size: return 1
			return suffix_to_rank[x+val_of_two][0]-suffix_to_rank[y+val_of_two][0]
	sorted_new_index = sorted(range(size), cmp=compare)
	rank = 0
	prev = sorted_new_index[0]
	new_ranks = [(0, prev)]
	for el in sorted_new_index[1:]:
		if compare(el,prev) != 0:
			rank += 1
			prev = el
		new_ranks.append((rank, el))
	new_suffix_to_rank = [0 for _ in xrange(size)]
	for el in new_ranks:
		new_suffix_to_rank[el[1]]= el
	suffix_to_rank = new_suffix_to_rank


print map(lambda x: raw[x[1]:], sorted(suffix_to_rank, key=lambda x: x[0]))




