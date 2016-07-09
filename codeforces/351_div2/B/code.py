from collections import Counter
_len = int(raw_input())
string = raw_input().strip()

if len(string) > 26:
	print -1
else:
	cnt = Counter(string)
	total = 0
	for key in cnt:
		total += cnt[key] - 1
	print total