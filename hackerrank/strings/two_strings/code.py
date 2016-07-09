import sys

num_cases = int(sys.stdin.readline().split()[0])
def create_table(S):
	table = [0 for i in range(65356)]
	for letter in S:
		table[ord(letter)] += 1
	return table

def lookup(table, S):
	found = False
	for letter in S:
		if table[ord(letter)] > 0:
			found = True
			break
	return found

for i in range(num_cases):
	A = sys.stdin.readline().split()[0]	
	B = sys.stdin.readline().split()[0]
	ascii_table = create_table(A)
	answer = 'YES' if lookup(ascii_table, B) else 'NO'
	print answer
