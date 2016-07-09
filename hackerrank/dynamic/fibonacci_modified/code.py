import sys
from math import *


numbers = sys.stdin.readline().split()
A = int(numbers[0])
B = int(numbers[1])
N = int(numbers[2])

result = [0]*(N)

for i in range(N):
    if i == 0: 
        result[i] = A
    elif i == 1:
        result[i] = B
    else:
        result[i] = result[i-1]**2 + result[i-2]
print result[-1]