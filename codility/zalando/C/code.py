def solution(A):
	N = len(A)
	B = A[:]
	B.sort()
	l = 0
	r = N-1
	while(l <= N-1 and A[l] == B[l]):
		l+=1

	while(r >= 0 and A[r] == B[r]): 
		r-=1
	if (r < l): return 0
	return r-l+1
A = [int(k) for k in raw_input().split()]

print solution(A)