import sys

def unify_string(word):
	alphabet = [0 for i in range(26)]
	for letter in word:
		alphabet[ord(letter)-ord('a')] += 1
	unified = "".join([str(val) + "" + chr(97+i) for (i, val) in enumerate(alphabet)])
	return unified

def solution(word):
	hashtable = {}
	for length in range(1, len(word)):
		for i in range(len(word)-length+1):
			unified = unify_string(word[i:i+length])
			if unified in hashtable:
				hashtable[unified] += 1
			else:
				hashtable[unified] = 1
	result = 0
	for key in hashtable:
		repeat = hashtable[key]
		if repeat > 1:
			result += repeat*(repeat-1)/2
	return result
num_cases = int(raw_input())

for i in range(num_cases):
	word = raw_input()
	print solution(word)