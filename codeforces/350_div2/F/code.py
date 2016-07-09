from collections import Counter
import math

def solution(line, subs):
	#first find the length of added number it cannot exceed 7
	original = len(line)
	while True:
		to_str = str(original)
		if original + len(to_str) == len(line): break
		else:
			original -= 1

	cntr = Counter(line)

	original = str(original)

	for char in original:
		cntr[int(char)] -= 1
	for char in subs[1:]:
		cntr[int(char)] -= 1
	index = 0
	for i in xrange(1, 10):
		if cntr[i] > 0: 
			index = i
			break
	cntr[index] -= 1
	if cntr[index] == 0 and int(subs[0]) == index:
		minimum = str(index) + subs[1:] + "".join(["0" for _ in xrange(cntr[0])])
	else: minimum = str(index) + "".join(["0" for _ in xrange(cntr[0])])

	if int(subs[0]) == 0:
		minimum += subs[1:]
	cntr[0] = 0
	for i in xrange(1, 10):
		if cntr[i] == 0: continue
		if len(subs) > 1:
			if int(subs[1]) < i and i == int(subs[0]):
				minimum += str(i) + subs[1:] + "".join([str(i) for _ in xrange(cntr[i]-1)])
			elif int(subs[1] > i) and i == int(subs[0]):
				minimum += "".join([str(i) for _ in xrange(cntr[i])]) + subs[1:]	
			else:
				minimum += "".join([str(i) for _ in xrange(cntr[i])])
		else:
			minimum += "".join([str(i) for _ in xrange(cntr[i])])
			
	print minimum

line = [int(x) for x in raw_input().strip()]
subs = raw_input().strip()

solution(line, subs)