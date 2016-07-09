def solution(num_coins, k, coins):
	if coins[0] == coins[-1]: return 0

	pointers_to_last = []
	pointers_to_first = [0]
	prev = coins[0]
	# print 'number of operations', k
	# print 'initial coins: ', coins

	for index, coin in enumerate(coins):
		if coin != prev:
			pointers_to_last.append(index-1)
			pointers_to_first.append(index)
			prev = coin

	pointers_to_last.append(num_coins-1)

	for _ in xrange(k): #decrease biggest
		if len(pointers_to_last) == 1:
			coins[0] -= 1
			pointers_to_first = [0, 1]
			pointers_to_last = [0, num_coins-1]
		_max = coins[-1]
		_second_max = coins[pointers_to_last[-2]]
		if pointers_to_last[-1] == pointers_to_first[-1]: #maximum element is only one
			if _max > _second_max + 1:
				coins[-1] -= 1
			else:
				pointers_to_first.pop()
				pointers_to_last.pop()
				pointers_to_last[-1] = num_coins-1
				coins[-1] -= 1
		else:
			coins[pointers_to_first[-1]] -= 1
			if _max == _second_max + 1:
				pointers_to_first[-1] += 1
				pointers_to_last[-2] += 1
			else:
				pointers_to_last[-1] = pointers_to_first[-1]
				pointers_to_last.append(num_coins-1)
				pointers_to_first.append(pointers_to_first[-1]+1)

	# print 'coins after increasing: ', coins

	for _ in xrange(k): #increase smallest
		if len(pointers_to_last) == 1:
			coins[-1] += 1
			pointers_to_first = [0, num_coins-1]
			pointers_to_last = [num_coins-2, num_coins-1]
		_min = coins[0]
		_second_min = coins[pointers_to_first[1]]
		if pointers_to_last[0] == pointers_to_first[0]: #minimum element is only one
			if _min < _second_min - 1:
				coins[0] += 1
			else:
				pointers_to_first.pop(0)
				pointers_to_first[0] = 0
				pointers_to_last.pop(0)
				coins[0] += 1
		else:
			coins[pointers_to_last[0]] += 1
			if _max == _second_max + 1:
				pointers_to_first[1] -= 1
				pointers_to_last[0] -= 1
			else:
				pointers_to_last.insert(pointers_to_last[0]-1, 0)
				pointers_to_first.insert(0, 0)
				pointers_to_first[1] = pointers_to_last[0] + 1

	# print 'coins after decreasing', coins

	return coins[-1]-coins[0]




line = raw_input().split()
num_coins = int(line[0])
k = int(line[1])
coins = sorted([ int(x) for x in raw_input().split() ])

print solution(num_coins, k, coins)