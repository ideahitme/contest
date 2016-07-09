#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;


ll gcd(int a, int b, ll res){
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

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	ll g;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	g = a[0];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		g = gcd(g, a[i], 1);
	
	}
	ll sqr = floor(sqrt(g)) + 2;
	ll min_remain = k;
	bool is_prime = true;
	for(ll i = 2; i <= sqr; i++){
		if (g % i == 0 && i <= k){
			is_prime = false;
			ll cand1 = k % i;
			// cout << cand << " " << sqr << " " << min_remain;
			if (cand1 < min_remain) min_remain = cand1;
			ll second = (g/i);
			if (second > 1 && second <= k){
				ll cand2 = k % second;
				// cout << cand << " " << sqr << " " << min_remain;
				if (cand2 < min_remain) min_remain = cand2;
			}
		}
	}
	if (is_prime && g <= k){
		min_remain = k%g;
	}
	cout << (k-min_remain) << endl;
	return 0;
}
