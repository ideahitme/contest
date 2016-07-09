#! /usr/bin/env python

def solution(array, modulo):
	prefix_sum = [{"index": 0, "value":array[0]}]
	for el in array[1:]:
		new_val = (prefix_sum[-1]["value"] + el) % modulo
		index = prefix_sum[-1]["index"] + 1
		prefix_sum.append({
			"index": index,
			"value": new_val 
			})
	prefix_sum.sort(key=lambda x: x["value"])
	return prefix_sum
num_cases = int(raw_input())

for _ in xrange(num_cases):
	line = raw_input().split()
	array_length = int(line[0])
	modulo = int(line[1])
	array = [int(x) for x in raw_input().split()]
	print solution(array, modulo)

