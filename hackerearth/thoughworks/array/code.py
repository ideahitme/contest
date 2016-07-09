n = int(raw_input())
a = [int(x) for x in raw_input().split()]

def gcd(a, b, res=1):
	if a % b == 0: return res * b;
	if b % a == 0: return res * a;
	if a == b: return res * a;
	if a % 2 == 0 and b % 2 == 0: return gcd(a/2, b/2, res*2);
	if a % 2 == 0: return gcd(a/2, b, res);
	if b % 2 == 0: return gcd(a, b/2, res);
	if a > b: return gcd(a-b, b, res);
	if a < b: return gcd(a, b-a, res);
	return 0

MAX = int(1e9+7)
ldp = [1 for i in xrange(n)]
for i in xrange(1, n):
	for j in xrange(i):
		# if a[i] > a[j]:
		ldp[i] += ldp[j]
		ldp[i] = int(ldp[i] % MAX)

dp = [0 for i in xrange(n)]
for i in xrange(0, n):
	sub = 0
	for j in xrange(i+1):
		if gcd(a[i], a[j]) == 1:
			sub += ldp[j]
	dp[i] = sub % MAX
answer = 0
for val in dp:
	answer += val
	answer = answer % MAX
print answer

