import sys

line = raw_input()
mod_num = int(pow(10,9))+7
N = int(line.split()[0])
M = int(line.split()[1])

big = max(N, M)
small = min(N, M)

if small == 1: 
	print 1
else:
	factorials = [0 for _ in range(small+1)]
	factorials[1] = 1
	for i in range(2, small+1):
		factorials[i] = (factorials[i-1]*i) % mod_num

	res = 1

	for _ in range(big-small+1):
		res = (res * factorials[small]) % mod_num

	for i in range(1, small):
		res = (res * factorials[i] * factorials[i]) % mod_num

	print res