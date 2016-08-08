#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1e9 + 7;
const int PRIME = 1e9 + 7;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<ll> c(n);
	vector<int> caps;
	vector<bool> is_cap(n, false);
	ll total = 0;	
	ll total_cap = 0;
	for(int i = 0; i < n; i++){
		cin >> c[i];
		total += c[i];
	}
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		x--;
		caps.push_back(x);
		is_cap[x] = true;
		total_cap += c[x];
	}
	ll ans = 0;
	ll to_rem = 0;
	for(int i = 0; i < caps.size(); i++){
		int id = caps[i];
		ans += c[id]*(total-c[id]);
		to_rem += c[id]*(total_cap-c[id]);
	}
	ans -= to_rem/2;
	for(int i = 0; i < n; i++){
		if (i == n-1){
			if (!is_cap[n-1] && !is_cap[0]){
				ans += c[i]*c[0];
			}
		}
		else {
			if (!is_cap[i] && !is_cap[i+1]){
				ans += c[i]*c[i+1];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
