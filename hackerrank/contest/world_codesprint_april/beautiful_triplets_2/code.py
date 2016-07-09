import sys

first_line = raw_input()
length = int(first_line.split()[0])
d = int(first_line.split()[1])

numbers = [int(n) for n in raw_input().split()]

count_array = [0 for i in range(21000)]
good_array = [0 for i in range(21000)]
for num in numbers:
	count_array[num] = 1
for num in range(len(count_array)):
	if count_array[num] == 1 and count_array[num+d] == 1:
		good_array[num] = 1
result = 0
for num in range(len(good_array)):
	if good_array[num] == 1 and good_array[num+d] == 1:
		result += 1

print result

