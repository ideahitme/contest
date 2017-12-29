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
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int>> inv(n, vector<int>(n, 0));
	for(int size = 0; size < n; size++) {
		for(int i = 0; i + size < n; i++) {
			if (size == 0) { inv[i][i+size] = 0;  }
			if (size == 1) { if (a[i+size] < a[i]) inv[i][i+size] = 1;  }
			if (size > 1) inv[i][i+size] = inv[i][i+size-1] + inv[i+1][i+size] - inv[i+1][i+size-1];
		}
	}
    ll total = inv[0][n-1];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        
    }
	return 0;
}