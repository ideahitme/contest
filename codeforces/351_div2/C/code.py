import math

def dist_points(A, B):
	return math.sqrt(math.pow(A[0]-B[0],2)+math.pow(A[1]-B[1],2))

def solution(points, A, B, R, total_if_all):
	if len(points) == 0:
		return 0.0
	if len(points) == 1:
		return min(A[0]+R[0], B[0]+R[0])
	else:
		total_A = total_if_all - R[0] + A[0]
		shortest_A = 0
		total_B = total_if_all - R[0] + B[0]
		shortest_B = 0
		for point in xrange(0, len(points)):
			candidate_A = total_if_all - R[point] + A[point]
			candidate_B = total_if_all - R[point] + B[point]
			if total_A > candidate_A:
				shortest_A = point
				total_A = candidate_A
			if total_B > candidate_B:
				shortest_B = point
				total_B = candidate_B

		all_candidates = [
			total_A, total_B
		]
		
		second_shortest_A = 0 if shortest_A > 0 else 1
		total_A = total_if_all - R[second_shortest_A] + A[second_shortest_A]
		second_shortest_B = 0 if shortest_B > 0 else 1
		total_B = total_if_all - R[second_shortest_B] + B[second_shortest_B]
		for point in xrange(0, len(points)):
			if point != shortest_A:
				candidate_A = total_if_all - R[point] + A[point]
				if total_A > candidate_A:
					second_shortest_A = point
					total_A = candidate_A
			if point != shortest_B:
				candidate_B = total_if_all - R[point] + B[point]
				if total_B > candidate_B:
					second_shortest_B = point
					total_B = candidate_B

		if shortest_A != shortest_B:
			all_candidates.append(total_if_all - R[shortest_A] + A[shortest_A] - R[shortest_B] + B[shortest_B])
		else:
			all_candidates.append(total_if_all - R[shortest_A] + A[shortest_A] - R[second_shortest_B] + B[second_shortest_B])
			all_candidates.append(total_if_all - R[second_shortest_A] + A[second_shortest_A] - R[shortest_B] + B[shortest_B])
		return min(all_candidates)

line = raw_input().strip().split()

pos_A = (int(line[0]), int(line[1]))
pos_B = (int(line[2]), int(line[3]))
R = (int(line[4]), int(line[5]))

#cases when either of them don't walk at all

total_points = int(raw_input())
points = []
for _ in xrange(total_points):
	line = raw_input().split()
	points.append((int(line[0]), int(line[1])))


from_recycle_to_points = []

for _ in xrange(total_points):
	dist = dist_points(points[_], R)
	from_recycle_to_points.append(dist)

from_A_to_points = []

for _ in xrange(total_points):
	dist = dist_points(points[_], pos_A)
	from_A_to_points.append(dist)

from_B_to_points = []

for _ in xrange(total_points):
	dist = dist_points(points[_], pos_B)
	from_B_to_points.append(dist)

total_if_all = 0

for el in from_recycle_to_points:
	total_if_all += 2*el

print solution(points, from_A_to_points, from_B_to_points, from_recycle_to_points, total_if_all)
