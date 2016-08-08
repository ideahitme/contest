#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e9;
const ll lMAX = 1e15;
const int PRIME = 1e9+7;

ll lca(ll a, ll b){
	if (a == 1 || b == 1) return 1ll;
	if (a == b) return a;
	while(true){
		if (a > b){
			a = a/2;
		}
		if (b > a){
			b = b/2;
		}
		if (a == b || a == 1 || b == 1) break;
	}
	return min({a,b});
}

struct path{
	ll par;
	ll to;
	int price;
	path(ll par, ll to, int price):par(par), to(to), price(price) {}
	ll add_path(ll from, ll child){
		if (child <= par) return 0ll;
		if (from >= to) return 0ll;
		ll total = 0ll;
		ll cur = child;
		ll cpc = to;
		bool found = false;
		while(cur != from){
			if (cur == cpc) found = true;
			if (found && cur > par){
				total += static_cast<long long>(price);
			}
			if (!found && cur > cpc) cur = cur/2;
			else if (!found) cpc = cpc/2;
			if (found) cur = cur/2;
		}
		return total;
	}
};
int main(int argc, char const *argv[])
{
	int q;
	cin >> q;
	vector<path> p;
	for(int i = 0; i < q; i++){
		int t;
		cin >> t;
		if (t == 1){
			ll v, u;
			int w;
			cin >> v >> u >> w;
			ll par = lca(v, u);
			if (par != v) {
				path n(par, v, w);
				p.push_back(n);
			}
			if (par != u) {
				path n(par, u, w);
				p.push_back(n);
			}
		}
		if (t == 2){
			ll v, u;
			cin >> v >> u;
			ll par = lca(v, u);
			ll total = 0;
			for(int i = 0; i < p.size(); i++){
				path s = p[i];
				if (par != v) {
					total += s.add_path(par, v);
				}
				if (par != u){
					total += s.add_path(par, u);
				}
			}
			cout << total << endl;
		}
	}
	/* code */
	return 0;
}

