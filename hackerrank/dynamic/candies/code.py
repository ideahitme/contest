import sys

num_children = int(sys.stdin.readline().split()[0])
children = [ int(sys.stdin.readline().split()[0]) for i in range(num_children) ]

incr_seq = [0 for i in children]
decr_seq = [0 for i in children]
incr_seq[0] = 1
decr_seq[-1] = 1
inc_rate = 1
for i in range(1, len(children)):
	if children[i-1] < children[i]:
		inc_rate += 1
	else: 
		inc_rate = 1		
	incr_seq[i] = inc_rate

dec_rate = 1
for i in range(len(children)-2,-1,-1):
	if children[i+1] < children[i]: 
		dec_rate += 1
	else:
		dec_rate = 1
	decr_seq[i] = dec_rate	


sum = 0
for i in range(num_children):
	sum += max(incr_seq[i], decr_seq[i])
print sum