num_cases = int(raw_input())


def solution(letters):
	counts = {'a': 0, 'b': 0, 'c': 0}
	def frequent_letter():
		return sorted(counts.items(), key = lambda x: x[1])[-1][0]
	def count(letter):
		counts[letter] += 1
	[count(letter) for letter in letters]
	while True:
		to_swap = frequent_letter()
		swapped = False
		for index, letter in enumerate(letters):
			if index > 0 and (letter == to_swap or letters[index-1] == to_swap) and letter != letters[index-1]:
				swapped = True
				new_letter = set(["a","b","c"]) - set([letter, letters[index-1]])
				counts[letter] -= 1
				counts[letters[index-1]] -= 1
				counts[list(new_letter)[0]] += 1				
				letters = letters[:index-1] + list(new_letter) + letters[index+1:]
				break
		if not swapped: break
	return len(letters)


for x in xrange(num_cases):
	letters = list(raw_input().strip())
	print solution(letters)
