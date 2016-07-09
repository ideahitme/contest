def solution(S):
	_max = -1
	curMax = 0
	foundUpper = False
	for char in S:
		if (ord(char) >= 48 and ord(char) <= 57):
			curMax = 0
			foundUpper = False
		else:
			curMax+=1
			if (ord(char) >= 65 and ord(char) <= 90):
				foundUpper = True
			if (curMax > _max and foundUpper):
				_max = curMax
	return _max


pw = raw_input().strip()

solution(pw)

print solution(pw)