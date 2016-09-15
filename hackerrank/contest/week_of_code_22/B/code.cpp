#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int total = 0;
	int _m = -1;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		total += x;
		_m = max({x, _m});
	}
	if (_m >= (total - _m)) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}
