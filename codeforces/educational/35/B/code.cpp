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
	int n, a, b;
	cin >> n >> a >> b;
	int answer = 1;
	for(int i = 1; i < n; i++) {
		int j = n-i;
		answer = max(answer, min(a/i, b/j));
	}
	cout << answer << endl;
	return 0;
}