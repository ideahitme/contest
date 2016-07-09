def get_count_array(list):
	count_array = range(10001)
	for el in list:
		count_array[el] += 1
	return count_array

def solution(first_list, second_list):
	first_count = get_count_array(first_list)
	second_count = get_count_array(second_list)
	for i in xrange(10001):
		if first_count[i] != second_count[i]:
			print i,

first_size = int(raw_input())
first_list = [int(x) for x in raw_input().split()]
second_size = int(raw_input())
second_list = [int(x) for x in raw_input().split()]

solution(first_list, second_list)