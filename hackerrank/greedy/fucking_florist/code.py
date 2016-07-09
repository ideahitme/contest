import sys

def calc_sum(start, end, prices):
	sum = 0
	for i in range(start, end):
		sum += prices[i]
	return sum

first_line = sys.stdin.readline().split()
num_flowers = int(first_line[0])
num_people = int(first_line[1])

prices = [int(num) for num in sys.stdin.readline().split()]
prices.sort()
if (num_people >= num_flowers): print calc_sum(0, 3, prices)
else:
	end = num_flowers
	visits = 1
	total = 0
	while(True):
		if end <= num_people:
			total += visits * calc_sum(0, end, prices)
			break
		else: 
			total += visits * calc_sum(end - num_people, end, prices)
			visits += 1
			end -= num_people
	print total


