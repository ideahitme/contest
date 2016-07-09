#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll sum_in_range(int l, int r, vector<ll> &prefix){
	if (l == 0) return prefix[r];
	else return prefix[r] - prefix[l-1];
}

bool is_prime(int n){
	if (n == 2) return true;
	bool is = true;
	int s = floor(sqrt(n)) + 1;
	for(int j = 2; j <= s; j++){
		if (n % j == 0) {
			is = false; 
			break;
		}
	}
	return is;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<ll> prefix(n);
	ll so_far = 0;
	for(int i = 0; i < n; i++){
		so_far += a[i];
		prefix[i] = so_far;
	}
	vector<int> primes;
	for(int i = 2; i < 5101; i++){
		if (is_prime(i)) primes.push_back(i);
	}
	// for(int i = 0; i < primes.size(); i++){
	// 	cout << primes[i] << endl;
	// }
	vector<ll> dp(n);
	for(int i = 0; i < n; i++){
		if (i == 0) dp[i] = 0;
		else if (i == 1) dp[i] = a[0] + a[1];
		else {
			ll _max = dp[i-1];
			int cur = 0;
			while(primes[cur] <= i + 1){
				ll to_compare;
				if (primes[cur] == i + 1){
					ll cand = prefix[i];
					if (cand > _max) _max = cand;
				} else {
					ll addon = ( i >= primes[cur] + 1 ) ? dp[i-primes[cur]-1] : 0;
					ll cand = sum_in_range(i-primes[cur]+1,i,prefix) +  addon;
					if (cand > _max) _max = cand;
				}
				cur++;
			}
			dp[i] = _max;
		}
	}
	cout << dp[n-1] << endl;
	/* code */
	return 0;
}
