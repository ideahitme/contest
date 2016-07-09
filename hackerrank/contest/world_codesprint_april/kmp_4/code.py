def toString(xs):
	result = []
	col = [[el for _ in range(rep)] for (rep, el) in xs]
	for arr in col:
		result += arr
	return result

def starting_point_of_char(xs, what_to_insert):
	result = 0
	for (rep, el) in xs:
		if el == what_to_insert: break
		result += rep
	return result

def swap(mystring, pos1, pos2):
	tmp = mystring[pos1]
	mystring[pos1] = mystring[pos2]
	mystring[pos2] = tmp

def construct(mystring, xs):
	if xs[0][0] <= 2:
		return mystring
	else:
		to_swap = xs[1][1]
		from_where = starting_point_of_char(xs, to_swap)+(xs[0][0] + 1) % 2
		cur = 2
		while cur <= xs[0][0] - 1:
			swap(mystring, cur, from_where)
			cur += 2
			from_where += 2
		return mystring

xs = [(int(x), chr(97+index)) for index, x in enumerate(raw_input().split()) if int(x) > 0]

_min = 0
for i in range(1, len(xs)):
	if xs[_min][0] > xs[i][0]:
		_min = i

if len(xs) == 0:
	print ""
elif len(xs) == 1: 
	print "".join(toString(xs))
elif _min != 0:
	answer = toString(xs)
	at = starting_point_of_char(xs, xs[_min][1])
	toInsert = answer.pop(at)
	answer.insert(0, toInsert)
	print "".join(answer)
else:
	mystring = toString(xs)	
	print "".join(construct(mystring, xs))

