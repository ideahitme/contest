#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int b, w;
	cin >> b >> w;	
	vector<pii> x(n-1);
	for(int i = 0; i < n-1; i++){
		int p,q;
		cin >> p >> q;
		x[i] = {p, q};
	}
	sort(x.begin(), x.end());
	for(int i = 0; i < n-1; i++){
		cout << x[i].first << " " << x[i].second << endl;
	}
	cout << (lower_bound(x.begin(), x.end(), {b, 0}) - x.begin()) << endl;
	return 0;
}
