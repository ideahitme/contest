#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

void print(vector<pii> &x) {
	for(int i = 0; i < x.size(); i++) {
		cout << x[i].first << " " << x[i].second << endl;
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	// vector<pii> x(m);
	int ans = 0;
	for(int i = 0; i < m; i++){
		int l, r;
		int sum = 0;
		cin >> l >> r;
		l--;r--;
		for(int j = l; j < r+1; j++){
			sum += a[j];
		}
		if (sum > 0) {
			ans += sum;
		}
	}
	cout << ans << endl;
	// vector<pii> u;
	// u.push_back({x[0].first, x[0].second});

	// for(int i = 1; i < m; i++){
	// 	if (x[i].first == x[i-1].first && x[i].second == x[i-1].second) {
	// 		continue;
	// 	}
	// 	u.push_back({x[i].first, x[i].second});
	// }

	/* code */
	return 0;
}


