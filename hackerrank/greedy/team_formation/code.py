from collections import Counter
from copy import copy
def recur_min_form_possible(unique_group, candidate_length, counter):
	if len(unique_group) < candidate_length: return False
	to_remove_left = unique_group[0]
	to_remove_right = unique_group[-1]
	to_remove_left_freq = counter[to_remove_left]
	to_remove_right_freq = counter[to_remove_right]

	broken = False
	for el in unique_group[:candidate_length]:
		counter[el] -= to_remove_left_freq
		if counter[el] < 0:
			broken = True
			break
	for el in reversed(unique_group[-candidate_length:]):
		counter[el] -= to_remove_right_freq
		if counter[el] < 0:
			broken = True
			break
	if broken: 
		return False
	new_unique_group = []
	for el in unique_group:
		if counter[el] > 0:
			new_unique_group.append(el)	
	if len(new_unique_group) < candidate_length: return True
	else:
		return recur_min_form_possible(new_unique_group, candidate_length, counter)

def calc_counter(group):
	cnt = Counter()
	for el in group:
		cnt[el] += 1
	return cnt	

def get_min_formation(group):
	#prepare the group by calculating the frequency of each member
	#then go from left to right and right to left calculating non-decreasing and non-decreasing sequences
	#pick min of them, that should be the contender, if contender not possible, try smaller one
	counter = calc_counter(group)
	unique_group = [group[0]]
	for el in group[1:]:
		if el != unique_group[-1]:
			unique_group.append(el)
	max_left = 1
	for el in unique_group[1:]:
		if counter[el] < counter[unique_group[0]]: break
		else:
			max_left += 1
	max_right = 1
	for el in reversed(unique_group[:-1]):
		if counter[el] < counter[unique_group[-1]]: break
		else:
			max_right += 1
	if max_left == max_right and max_left == len(unique_group) and counter.most_common(1)[0][1] == counter[unique_group[0]]:
		return max_left
	candidate = min(max_left, max_right)
	while candidate > 1:
		cpy = unique_group[:]
		counter_cpy = copy(counter)
		if recur_min_form_possible(cpy, candidate, counter_cpy): break
		else:
			candidate -= 1
	return candidate


def solution(skills):
	group = [skills[0]]
	min_so_far = len(skills)
	for i in xrange(1, len(skills)):
		if skills[i] - skills[i-1] > 1:
			min_form = get_min_formation(group)
			if min_form == 1: 
				group = []
				min_so_far = 1
				break
			if min_form < min_so_far: min_so_far = min_form
			group = [skills[i]]
		else:
			group.append(skills[i])
	if len(group) > 0:
		min_form = get_min_formation(group)
		if min_form < min_so_far: min_so_far = min_form
	return min_so_far


num_cases = int(raw_input())

for _ in xrange(num_cases):
	line = raw_input().strip().split()
	num_people = int(line[0])
	if num_people == 0: 
		print "0"
		continue
	else:
		skills = [int(x) for x in line[1:]]
		skills.sort()
		print solution(skills)
