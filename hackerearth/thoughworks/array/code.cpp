#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const ll MAX = (ll)1e9+7;

ll gcd(ll a, ll b, ll res){
	if (a % b == 0) return res * b;
	if (b % a == 0) return res * a;
	if (a == b) return res * a;
	if (a % 2 == 0 && b % 2 == 0) return gcd(a/2, b/2, res*2);
	if (a % 2 == 0) return gcd(a/2, b, res);
	if (b % 2 == 0) return gcd(a, b/2, res);
	if (a > b) return gcd(a-b, b, res);
	if (a < b) return gcd(a, b-a, res);
	return 0ll;
}

ll find_gcd(ll a,ll b){
	return gcd(a, b, 1);
}

int main(int argc, char const *argv[])
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}	
	ll total = 0;
	vector<ll> ldp(n, 1);
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if (a[j] < a[i]){
				ldp[i] += ldp[j];
				ldp[i] = ldp[i] % MAX;
			}
		}
	}
	// for(int i = 0; i < n; i++)
		// cout << i << " " << ldp[i] << endl;
	vector<ll> dp(n);
	
	dp[0] = (a[0] == 1) ? 1:0;

	for(ll i = 1; i < n; i++){
		ll sub_total = ldp[i];
		for(ll j = 0; j < i; j++){
			if (find_gcd(a[i], a[j]) != 1ll && a[i] > a[j]){
				sub_total -= ldp[j];
			}
		}
		if (a[i] != 1) sub_total--;
		dp[i] = sub_total % MAX;
	}
	ll answer = 0;
	for(ll i = 0; i < n; i++){
		answer += dp[i];
		answer = answer % MAX;
	}
	cout << answer << endl;
	return 0;
}
