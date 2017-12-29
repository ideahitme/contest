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
	for(int i = 0; i < n; i++) { cin >> a[i]; }

	int my_min = MAX;
	int cur_index = -1;
	int answer = MAX;
	for(int i = 0; i < n; i++) {
		if (a[i] < my_min) my_min = a[i];
	}
	for(int i = 0; i < n; i++) {
		if (a[i] != my_min) continue;
		if (cur_index == -1) {
			cur_index = i;
			continue;
		}
		if (i - cur_index < answer) {
			answer = i - cur_index;
		}
        cur_index = i;
    }

	cout << answer << endl;

	return 0;
}