_len = int(raw_input())
string = raw_input()

def solution(string):
	if len(string) < 3: return 0
	i = 0;
	changes = 0
	while i <= len(string)-3:
		if string[i:i+3] == "010":
			if i <= len(string)-5:
				if string[i+3:i+5] == "10":
					i = i + 4
				else:
					i = i + 2
				changes += 1	
			else:
				changes += 1	
				break
		else:
			i += 1
	return changes
print solution(string)