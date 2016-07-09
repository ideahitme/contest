import sys

length = int(raw_input())
K = int(raw_input())
list = [int(raw_input()) for _ in range(length)]
list.sort()

result = list[-1]
i = 0
while i <= length-K:
	result = (list[i+K-1]-list[i]) if ((list[i+K-1]-list[i]) < result) else result
	i += 1
print result