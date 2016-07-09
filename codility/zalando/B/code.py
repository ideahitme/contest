import random

def solution(A):
    N = len(A)
    result = 0
    count = [[-1 for j in xrange(2)] for i in xrange(N+1)]
    for i in xrange(N):
    	val = A[i]
    	if count[val][0] == -1:
    		count[val][0] = i
    	else:
			count[val][1] = i
	for i in xrange(N):
		if count[val][0] != -1 and count[val][1] != -1:
			result = max(result, count[val][1]-count[val][0])
    return result

def alt(A):
    N = len(A)
    result = 0
    for i in xrange(N):
        for j in xrange(N):
            if A[i] == A[j]:
                result = max(result, abs(i - j))
    return result

for i in xrange(100):
    N = random.randint(1, 10000)
    A = [random.randint(1, N) for i in xrange(N)]
    print solution(A)

