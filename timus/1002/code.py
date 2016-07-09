import sys
import math

def convert(char):
	if char in ['a','b','c']: return '2' 
	if char in ['i','j']: return '1' 
	if char in ['d','e','f']: return '3' 
	if char in ['g','h']: return '4' 
	if char in ['k','l']: return '5' 
	if char in ['m','n']: return '6' 
	if char in ['p','r','s']: return '7' 
	if char in ['t','u','v']: return '8' 
	if char in ['w','x','y']: return '9' 
	if char in ['o','q','z']: return '0' 
	return '' 

def to_tuple(word):
	return (word, "".join([convert(char) for char in word]))

def solve(phone, candidates):
	dynamic = [[]]*(len(phone)+1)
	for i in range(1, len(phone)+1):
		found = False
		for (word, number) in candidates:
			tmp = None
			if len(word) <= i:
				if phone[0:i] == number: 
					dynamic[i] = [word]
					break
				if phone[i-len(word):i] == number and len(dynamic[i-len(word)]) > 0: 
					tmp = dynamic[i-len(word)][:]
					tmp.append(word)
					if not found: 
						dynamic[i] = tmp
						found = True
					else:
						if len(tmp) < len(dynamic[i]):
							dynamic[i] = tmp 
	return dynamic[-1]

while True:
	phone = sys.stdin.readline().split()[0]
	if phone == '-1': break
	total = sys.stdin.readline().split()[0]
	total = int(total)
	if total == 0: continue
	candidates = [to_tuple(sys.stdin.readline().split()[0]) for it in range(total)]
	solution = solve(phone, candidates)
	if len(solution) == 0:
		print 'No solution.'
	else: 
		print " ".join(solution)


