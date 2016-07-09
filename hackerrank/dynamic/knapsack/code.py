import sys

def solution(elements, expected_sum):
	min_sum = [i for i in range(2001)]
	for i in range(expected_sum+1):
		j = 0
		cur_min = i
		while j < len(elements) and elements[j] <= i:
			cur_min = min(min_sum[i-elements[j]], cur_min)
			j += 1
		min_sum[i] = cur_min		
	return min_sum[expected_sum]

num_test_cases = int(raw_input())

for i in range(num_test_cases):
	line = raw_input()
	num_elements = 	int(line.split()[0])
	expected_sum = int(line.split()[1])
	elements = [int(el) for el in raw_input().split()]
	elements.sort()
	print expected_sum - solution(elements, expected_sum)
