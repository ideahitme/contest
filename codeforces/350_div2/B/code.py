import math

line = raw_input().strip().split()

num_robots = int(line[0])
k = int(line[1])

array = [int(x) for x in raw_input().split()]

if k == 1:
	print array[0]
elif k == 2:
	print array[0]
elif k == 3:
	print array[1]
elif k == 4:
	print array[0]
else:
	guy_to_speak = int(math.ceil(math.sqrt(2*k)))
	if guy_to_speak*(guy_to_speak+1)/2 > k:
		guy_to_speak = guy_to_speak-1
	about_who = k % guy_to_speak
	if about_who == 0:
		print array[guy_to_speak-1]
	else: print array[about_who-1]


