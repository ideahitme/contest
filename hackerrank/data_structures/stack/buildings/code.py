import sys

num_buildings = int(raw_input())

hist = [int(h) for h in raw_input().split()]
answer = 0
stack = []
lefts = [h for h in range(len(hist))]
rights = [h for h in range(len(hist))]

for i in range(len(hist)):
	while len(stack) > 0 and hist[i] <= hist[stack[-1]]:
		el = stack.pop()	
	if len(stack) == 0:
		lefts[i] = 0
	else:
		lefts[i] = stack[-1] + 1
	stack.append(i)
stack = []
for i in range(len(hist)-1,-1,-1):
	while len(stack) > 0 and hist[i] <= hist[stack[-1]]:
		last = stack.pop()			
		rights[i] = last
	if len(stack) == 0:
		rights[i] = len(hist)-1
	else: 
		rights[i] = stack[-1] - 1
	stack.append(i)

for i in range(len(hist)):
	val = (rights[i]-lefts[i]+1)*hist[i]
	answer = val if val >= answer else answer
print answer