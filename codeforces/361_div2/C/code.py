def num_soln(n):
	x = 2
	total = 0
	while (x*x*x <= n):
		total += n/(x*x*x)
		x+=1
	return total

def binary_search(l, r, x):
	if (l >= r):
		return l
	cand = int((l+r)/2)
	if (num_soln(cand) < x):
		return binary_search(cand+1, r, x)
	elif (num_soln(cand) == x):
		if (num_soln(cand-1) == x):
			return binary_search(l, cand-1, x)
		else: 
			return cand
	else: 
		return binary_search(l, cand, x)
def solution(m):
	ans = binary_search(2, 16*m, m)
	while(num_soln(ans-1) == m):
		ans-=1
	if (num_soln(ans) == m):
		print ans 
	else:
		print -1


m = int(raw_input())
solution(m)


# ll binary_search(ll l, ll r, ll x){
# 	if (l >= r){
# 		return l;
# 	}
# 	ll cand = (l+r)/2;
# 	if (num_soln(cand) < x){
# 		return binary_search(cand+1, r, x);
# 	}
# 	else if (num_soln(cand) == x){
# 		return cand;
# 	}
# 	else{
# 		return binary_search(l, cand, x);
# 	}
# }


# int main(int argc, char const *argv[])
# {
# 	ios::sync_with_stdio(false);
# 	/* code */
# 	ll m;
# 	cin >> m;
# 	ll ans = binary_search(2, 16*m, m);
# 	while(num_soln(ans-1) == m){
# 		ans--;
# 	}
# 	if (num_soln(ans) == m) cout << ans << endl;
# 	else cout << -1 << endl;
# 	return 0;
# }
