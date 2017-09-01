#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int ans = 0;
vector<pll> t;
int n,m;
vector<ll> x;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	t.resize(m);
	x.resize(n);
	for(int i = 0; i < n; i++){
		ll f;
		cin >> f;
		x[i] = f;
	}
	for(int i = 0; i < m; i++){
		ll u, f;
		cin >> u >> f;
		t[i] = {u-f,u+f};
	}
	sort(t.begin(), t.end());
	sort(x.begin(), x.end());
	multiset<ll> seg;
	for(int i = 0, j = 0; i < n;){
		ll cur_point = x[i];
		if (j < m && t[j].first <= cur_point){
			seg.insert(t[j].second);
			j++;
		} else {
			auto it = seg.lower_bound(cur_point);
			if (it != seg.end()){
				seg.erase(it);
				ans++;
			}
			i++;
		}
	}
	cout << ans << endl;
	return 0;
}

