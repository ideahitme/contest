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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> pow(n);
    pow[0] = 1LL;
    for(int i = 1; i <= n-2; i++) {
        pow[i] = pow[i-1] * (k-1);
        pow[i] %= PRIME;
    }
    ll total = 0;
    ll sign = 1;
    for(int i = n-2; i >= 0; i--) {
        if (i == 0 && x == 1) {
            break;
        }
        total += sign*pow[i];
        total %= PRIME;
        sign *= -1;
    }
    if (total < 0) {
        total += PRIME;
    }
    cout << total << endl;
	return 0;
}