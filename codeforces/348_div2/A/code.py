stones = int(raw_input())

if stones % 3 == 1:
	print 2*(stones-1)/3 + 1
if stones % 3 == 2:
	print 2*(stones-2)/3 + 1
if stones % 3 == 0:
	print 2*stones/3