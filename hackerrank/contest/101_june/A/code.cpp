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

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
		cin >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	if (x[0] == x[n-1] || y[0] == y[n-1]) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
 	return 0;
}
