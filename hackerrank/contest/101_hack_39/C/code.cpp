#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e9;
const ll lMAX = 1e15;
const double dMAX = static_cast<double>(1e15);

int prefix_range(int x, int y, const vector<int> &prefix){
	if (x == 0) return prefix[y];
	return (prefix[y] ^ prefix[x-1]);
}

int num_ones(int x, int y, const vector<int> &ones){	
	if (x == 0) return ones[y];
	return (ones[y] - ones[x-1]);

}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> prefix(n);
	vector<int> ones(n);
	int res = 0;
	int _ones = 0;
	for(int i = 0; i < n; i++){
		res = res ^ a[i];
		if (a[i] == 1) _ones++;
		prefix[i] = res;
		ones[i] = _ones;
	}
	for(int i = 0; i < q; i++){
		int x,y,k;
		cin >> x >> y >> k;
		ll total = 0;
		ll pre = 0;
		for(int i = y; i > x-1; i--){
			if (i == y){
				pre = a[i];
				total = pre;
			}
			else {
				if (a[i] == 1){
					total += (y-i+1)*(y-i)/2;
					total -= pre;
					pre = total; 
				}
				else {
					total += pre;
					pre = total;
				}
			}
		}
		//now try with changed
		int dx = x;
		while(a[dx] == 1){
			dx++;
		}
		ll cand = 0;
		if (dx <= y && k > 0){
			a[dx] = 1;
			ll ppre = 0;
			for(int i = y; i > x-1; i--){
				if (i == y){
					ppre = a[i];
					cand = ppre;
				}
				else {
					if (a[i] == 1){
						cand += (y-i+1)*(y-i)/2;
						cand -= ppre;
						ppre = cand; 
					}
					else {
						cand += ppre;
						ppre = cand;
					}
				}
			}
			a[dx] = 0;
		}
		// if (changed != -1) {
		// 	a[changed] = a[changed] ^ 1;
		// }
		cout << max({total, cand}) << endl;
	}
	// cout << "XOR 1 and 1 =" << (1^1) << endl;
	// cout << "XOR 1 and 0 =" << (1^0) << endl;
	// cout << "XOR 0 and 0 =" << (0^0) << endl;

	return 0;
}
