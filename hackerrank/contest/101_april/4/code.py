import sys

mod_num = 1000000007

def num_distinct(alphabet, start, end):
	dist = 0
	for key in alphabet:
		if alphabet[key][end]-alphabet[key][start] > 0:
			dist += 1
	return dist

def diff_substr(line):
	sub_dict = dict()
	for i in range(len(line)):
		j = i
		while j < len(line):
			substr = line[i:j+1]
			if substr not in sub_dict:
				sub_dict[substr] = {
					"start": i,
					"end": j+1
				}
			j += 1
	return sub_dict

def precalc_powers(length, upto):
	result = [[1 for _ in range(upto+1)] for _ in range(length+1)]
	for i in range(1, length+1):
		for j in range(1, upto+1):
			result[i][j] = ((result[i][j-1]*i) % mod_num)
	return result

def solution(word):
	alphabet = {}
	for letter in word:
		if letter not in alphabet:
			alphabet[letter] = [0]
	for letter in word:
		for key in alphabet:
			if key == letter:
				alphabet[key].append(alphabet[key][-1]+1)
			else:
				alphabet[key].append(alphabet[key][-1])
	res = 0
	powers = precalc_powers(len(word), num_distinct(alphabet, 0, len(word)))
	substrings = diff_substr(word)
	for subs in substrings:
		res += powers[len(subs)][num_distinct(alphabet, substrings[subs]["start"], substrings[subs]["end"])] % mod_num
	return (res%mod_num)

num_test = int(raw_input())
for _ in range(num_test):
	print solution(raw_input())

