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
	int n, w, v, u;
	cin >> n >> w >> v >> u;
	vector<pii> p(n);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		p[i] = {x,y};
	}
	return 0;
}
