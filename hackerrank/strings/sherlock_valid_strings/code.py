word = list(raw_input().strip())

count_array = [0 for _ in xrange(26)]

def increase_count_array(x):
	count_array[ord(x)-97] += 1

map(increase_count_array, word)
count_array = [el for el in count_array if el > 0]
_min = min(count_array)
min_check = [el-_min for el in count_array if el > _min]
check_min = True if len(min_check) <= 1 else False
_max = max(count_array)
max_check = [el for el in count_array if el < _max]
check_max = True if len(max_check) == 1 and max_check[0] == 1 else False
if check_min or check_max: print "YES"
else: print "NO"
