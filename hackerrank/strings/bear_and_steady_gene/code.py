import sys

word_len = int(sys.stdin.readline().split()[0])
goal = word_len/4
word = sys.stdin.readline().split()[0]

prefix_sum = {
	'A': [0 for i in range(word_len)],
	'C': [0 for i in range(word_len)],
	'T': [0 for i in range(word_len)],
	'G': [0 for i in range(word_len)]
}
i = 0
for gene in word:
	for letter in ['A', 'C', 'T', 'G']:
		if i == 0:
			if letter == gene:
				prefix_sum[letter][0] = 1
		elif letter == gene:
			prefix_sum[letter][i] = prefix_sum[letter][i-1] + 1
		else:
			prefix_sum[letter][i] = prefix_sum[letter][i-1]
	i += 1

def how_many_gene_from_to(gene, _from, to):#_from - min 0, to max word_len-1
	if _from == 0: return prefix_sum[gene][to]
	return prefix_sum[gene][to] - prefix_sum[gene][_from-1]
def deviation(gene):
	return prefix_sum[gene][word_len-1]-goal

def solvable(start, end):
	if deviation('A') > 0:
		if deviation('A') > how_many_gene_from_to('A', start, end):
			return False
	if deviation('C') > 0:
		if deviation('C') > how_many_gene_from_to('C', start, end):
			return False
	if deviation('T') > 0:
		if deviation('T') > how_many_gene_from_to('T', start, end):
			return False
	if deviation('G') > 0:
		if deviation('G') > how_many_gene_from_to('G', start, end):
			return False
	return True

def solution():
	answer = word_len
	start = 0
	end = 1
	while True:
		if start == end: break
		if end == (word_len-1) and not solvable(start, end):
			break
		if solvable(start, end): 
			answer = end - start + 1
			start += 1
		else:
			if (answer != word_len): start += 1
			end += 1
	return answer

if prefix_sum['A'][word_len-1] == goal and prefix_sum['C'][word_len-1] == goal and prefix_sum['T'][word_len-1] == goal and prefix_sum['G'][word_len-1] == goal:
	print 0
else: print solution()
