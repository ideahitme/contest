def solution(containers):
	all_xor = 0
	for container in containers:
		all_xor = all_xor ^ container

	total = 0

	for container in containers:
		without_container = all_xor ^ container
		if container > without_container:
			total += 1

	return total	

num_containers = int(raw_input())

containers = [int(k) for k in raw_input().split()]

print solution(containers)