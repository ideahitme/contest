import sys


total = int(sys.stdin.readline().split()[0])
values = [{'parity':None} for i in range(total)]

num_qns = int(sys.stdin.readline().split()[0])

for it in range(num_qns):
	line = sys.stdin.readline().split()
	start = int(line[0])
	end = int(line[1])
	parity = line[2]
	print start, end
	if start == 1:
		values[end-1]['parity'] = parity
		print values

for it in range(num_qns):
	line = sys.stdin.readline().split()
	start = int(line[0])
	end = int(line[1])
	parity = line[2]
	print start, end
	if start == 1:
		values[end-1]['parity'] = parity
		print values

