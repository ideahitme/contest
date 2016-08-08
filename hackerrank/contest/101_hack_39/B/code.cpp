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

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	int l = 0;
	int total = 0;
	while(true){
		if (l > n-1) break;
		int next = -1;
		for(int i = l; i < min({l+k, n}); i++){
			if (c[i] == 1) next = i;
		}
		if (next == -1) {
			//go backwards
			if (l == 0) { total = 0; break; }
			int m = l;
			bool bs = false;
			while(c[m] == 0){
				m--;
				if (m < 0 || m <= l-k){ 
					bs = true; break; 
				} 
			}
			if (bs){
				total = 0;
				break;
			}
			l = m;
			l += k;
			total++;
		}
		else {
			total++;
			l = next + k;
		}
	}
	if (total == 0) {
		cout << -1 << endl;
	} else {
		cout << total << endl;
	}
	return 0;
}
