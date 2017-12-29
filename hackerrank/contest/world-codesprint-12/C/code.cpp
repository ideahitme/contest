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

ll find(ll i, const vector<ll> &dp) {
    if (i == 1) return 1;
    vector<ll> div;
    ll c = i;
    for (ll j = 2; j <= ceil(sqrt(i)); j++) {
        if (c == 1) break;
        while(c % j == 0) {
            div.push_back(j);
            c /= j;
        }
    }
    if (div.size() == 0) {
        return 1 + i;
    }
    if (c != 1) {
        div.push_back(c);
    }
    sort(div.begin(), div.end());
    ll total = 1;
    for(int j = 0; j < div.size(); j++) {
        total = 1 + div[j]*total;
    }
    return total;
}

int main()
{
	ios::sync_with_stdio(false);

    vector<ll> dp(1e5+1, 0);
    dp[1] = 1LL;
    for(ll i = 2; i < 1e5+1; i++) {
        ll max = -1;
        ll c = i;
        for (ll j = 2; j <= ceil(sqrt(i)); j++) {
            if (c == 1) break;
            while(c % j == 0) {
                max = j;
                c /= j;
            }
        }
        if (max == -1) {
            dp[i] = 1 + i;
            continue;
        }
        if (max < c) max = c;
        dp[i] = 1 + max*dp[i/max];
    }

    int n;
    cin >> n;
    ll total = 0;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        total += find(x, dp);
    }

    cout << total << endl;

	return 0;
}