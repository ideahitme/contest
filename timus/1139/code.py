import sys

def gcd(a, b, res):
	if a % b == 0: return res * b;
	if b % a == 0: return res * a;
	if a == b: return res * a;
	if a % 2 == 0 and b % 2 == 0: return gcd(a/2, b/2, res*2);
	if a % 2 == 0: return gcd(a/2, b, res);
	if b % 2 == 0: return gcd(a, b/2, res);
	if a > b: return gcd(a-b, b, res);
	if a < b: return gcd(a, b-a, res);

def calc(a, b):
	if a == b: return 1
	return a+b-1

for line in sys.stdin:
	width = int(line.split()[0]) - 1 	
	height = int(line.split()[1]) - 1
	gre_com_div = gcd(width, height, 1)
	width = width/gre_com_div
	height = height/gre_com_div
	answer = gre_com_div * calc(width, height)
	print answer
