import math

def produce_ranks(word_list, index_sorted, size):
	ranks = [0 for _ in xrange(size)]
	rank = 0
	prev = word_list[index_sorted[0]]
	for i in xrange(size):
		if word_list[index_sorted[i]] != prev:
			rank += 1
			prev = word_list[index_sorted[i]]
		ranks[index_sorted[i]] = rank
	return ranks

word = raw_input().strip()
size = len(word)
word_list = list(word)
index_sorted = sorted(range(size), key=lambda x: word[x])

log = int(math.log(size, 2)) + 1
ranks = produce_ranks(word_list, index_sorted, size)
for power in xrange(log):
	power_of_two = int(math.pow(2, power))
	def compare(x,y):
		if ranks[x] < ranks[y]: return -1
		elif ranks[x] > ranks[y]: return 1
		else:
			if x + power_of_two > size - 1: return -1
			if y + power_of_two > size - 1: return 1
			return ranks[x+power_of_two]-ranks[y+power_of_two]
	index_sorted = sorted(range(size), cmp=compare)
	rank = 0
	prev = index_sorted[0]
	new_ranks = [0 for _ in xrange(size)]
	for i in xrange(size):
		if compare(index_sorted[i], prev) > 0:
			rank += 1
			prev = index_sorted[i]
		new_ranks[index_sorted[i]] = rank
	ranks = new_ranks

print ranks
print map(lambda x: word[x[0]:], sorted(enumerate(ranks), key=lambda x: x[1]))
