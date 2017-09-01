#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int q = 0; q < t; q++){
		int n;
		cin >> n;
		vector<ll> d(n);
		vector<ll> r(n+1, -1);
		r[0] = 0;
		vector<ll> x(n);
		for(int i = 0; i < n; i++) cin >> d[i];
		for(int i = 0; i < n; i++){
			ll rank = d[i];
			if (r[rank] == -1){
				x[i] = r[rank-1] + n + 1;
				r[rank] = r[rank-1] + n + 1;
			}
			else {
				x[i] = r[rank]-1;
				r[rank]--;
			}
		}
		for(int i = 0; i < n; i++) cout << x[i] << " ";
		cout << endl;
	}
	return 0;
}