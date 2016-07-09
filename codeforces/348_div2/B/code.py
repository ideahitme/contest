length = int(raw_input())

dirs = list(raw_input().strip())
jumps = [int(x) for x in raw_input().split()]

cur = 0
finite = False
for _ in xrange(length+1):
	if dirs[cur] == '>':
		cur += jumps[cur]
	else:
		cur -= jumps[cur]
	if cur < 0 or cur > length-1:
		finite = True
		break
if finite:
	print "FINITE"
else:
	print "INFINITE"