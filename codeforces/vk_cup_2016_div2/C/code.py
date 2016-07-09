import math
from random import randint

# num_balls = int(raw_input().strip())
# balls = [int(x)-1 for x in raw_input().split()]
num_balls = 4000
balls = [randint(0, 3999) for _ in xrange(num_balls)]

colors = [0 for x in xrange(num_balls)]
for left_pivot in xrange(num_balls):
	count = [0] * num_balls
	best = balls[left_pivot]
	count[balls[left_pivot]] += 1
	colors[best] += 1
	for at in xrange(left_pivot+1, num_balls):
		count[balls[at]] += 1
		if count[balls[at]] > count[best] or (count[balls[at]] == count[best] and balls[at] < best):
			best = balls[at]
		colors[best] += 1

for color in colors:
	print str(color), 