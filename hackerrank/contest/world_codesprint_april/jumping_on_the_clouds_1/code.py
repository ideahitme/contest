import sys

num_clouds = int(raw_input())

clouds = [int(c) for c in raw_input().split()]

total = 0
_prev = 0
_next = -1

for i, cloud in enumerate(clouds[0:]):
	if i == num_clouds - 1:
		_next += 1
		total += (_next - _prev)/2 + (_next - _prev) % 2
		break
	if cloud == 1:
		total += (_next - _prev)/2 + (_next - _prev) % 2 + 1
		_prev = i + 1
		_next = i
	else: 
		_next += 1

print total
