import sys
import math

def is_point_inside(point, start, end):
	return start <= point and point <= end

length = int(raw_input())
array = [int(val) for val in raw_input().split()]
array.sort()
last = raw_input().split()
P = int(last[0])
Q = int(last[1])


if Q <= array[0]:
	print (P-array[0])
elif P >= array[-1]:
	print (Q - array[-1])
else:
	checkpoints = []	
	if P < array[0]:
		checkpoints.append({
			"point": P,
			"diff": array[0] - P
		})
	else:
		for i in range(length-1):
			if is_point_inside(P, array[i], array[i+1]):
				checkpoints.append({
					"point": P,
					"diff": min(P-array[i], array[i+1]-P)
				})
				break

	for i in range(length-1):
		diff = (array[i+1]-array[i])/2
		if is_point_inside(array[i]+diff, P, Q):
			checkpoints.append({
				"point": array[i]+diff,
				"diff": diff
			})
	if Q >= array[-1]:
		checkpoints.append({
			"point": Q,
			"diff": Q - array[-1]
		})
	else:
		for i in range(length-1):
			if is_point_inside(Q, array[i], array[i+1]):
				checkpoints.append({
					"point": Q,
					"diff": min(Q-array[i], array[i+1]-Q)
				})
				break
	result = P
	_max = checkpoints[0]["diff"]
	for i in range(1, len(checkpoints)):
		if _max < checkpoints[i]["diff"]:
			_max = checkpoints[i]["diff"]
			result = checkpoints[i]["point"]
	print result