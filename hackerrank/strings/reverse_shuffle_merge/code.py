from collections import Counter

S = list(raw_input().strip())

count_array = [ [0 for x in xrange(len(S))] for _ in xrange(26) ]

for j in xrange(26):
	for i in xrange(len(S)):
		if i == 0:
			count_array[j][i] = 1 if ord(S[i]) - 97 == j else 0
		elif ord(S[i])-97 == j:
			count_array[j][i] = count_array[j][i-1] + 1
		else:
			count_array[j][i] = count_array[j][i-1]

goal = Counter(S)
for el in goal:
	goal[el] = goal[el]/2

i = len(S) - 1
res = ""

while i > -1:
	while goal[S[i]] < 1 and i > -1:
		i -= 1
	if i == -1: break
	_min = S[i]
	index = i
	while i > -1:
		char = S[i]
		_ord = ord(char) - 97
		if _min > S[i] and goal[S[i]] > 0:
			_min = S[i]
			index = i
		if count_array[_ord][i] - 1 < goal[S[i]]: break
		else: i -= 1
	res += _min
	i = index - 1
	goal[_min] -= 1

print res
