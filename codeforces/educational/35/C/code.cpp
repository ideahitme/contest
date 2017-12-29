#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int PRIME = 1e9+7;

const int MAX = - 1 + (1<<30) + (1<<30);
const int MIN = -(1<<31);
const ll lMAX = -1LL + (1LL<<62) + (1LL<<62);
const ll lMIN = -(1LL<<63);

int main()
{
	ios::sync_with_stdio(false);
	int a,b,c;
	cin >> a >> b >> c;
	vector<int> x{a,b,c};
	sort(x.begin(), x.end());
	if (x[0] == 1) {
		cout << "YES" << endl;
		return 0;
	}
	if (x[0] == 2 && x[1] == 2) {
		cout << "YES" << endl;
		return 0;
	}
	if (x[0] == 3 && x[1] == 3 && x[2] == 3) {
		cout << "YES" << endl;
		return 0;
	}
	if (x[0] == 2 && x[1] == 4 && x[2] == 4) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}