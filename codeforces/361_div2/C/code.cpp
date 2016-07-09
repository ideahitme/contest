#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e9+7;
const int MIN = -1e9;
const int PRIME = 1e9+7;
const ll lMAX = 1e15;
const ll lMIN = -1e15;


ll num_soln(ll n){
	ll x = 2;
	ll total = 0;
	while (x*x*x <= n){
		total += n/(x*x*x);
		x++;
	}
	return total;
}	


ll binary_search(ll l, ll r, ll x){
	if (l >= r){
		return l;
	}
	ll cand = (l+r)/2;
	if (num_soln(cand) < x){
		return binary_search(cand+1, r, x);
	}
	else if (num_soln(cand) == x){
		return cand;
	}
	else{
		return binary_search(l, cand, x);
	}
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	/* code */
	ll m;
	cin >> m;
	ll ans = binary_search(2, 16*m, m);
	while(num_soln(ans-1) == m){
		ans--;
	}
	if (num_soln(ans) == m) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}
