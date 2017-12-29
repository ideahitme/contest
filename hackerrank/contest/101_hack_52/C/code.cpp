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
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bool> has(1 << 20, false);
    vector<ll> lcnt(n, 0);
    vector<ll> rcnt(n, -1);
    int j = 0;
    for(ll i = 0; i < n; i++) {
        if (j == n) {
            lcnt[i] = j-i;
            continue;
        }
        for(;j < n && !has[a[j]]; j++) {
            has[a[j]] = true;
        }
        lcnt[i] = j-i;
        has[a[i]] = false;
    }

    for(ll i = 0; i < n; i++) {
        int next = i + lcnt[i]-1;
        if (rcnt[next] == -1) {
            rcnt[next] = i;
        }
    }
    ll val = rcnt[n-1];
    for(ll i = n-2; i > -1; i--) {
        if (rcnt[i] == -1) {
            rcnt[i] = val;
            continue;
        }
        val = rcnt[i];
    }

    vector<ll> total_cover(n, 0);
    for(ll i = 0; i < n; i++) {
        if (i == 0) {
            total_cover[i] = lcnt[i];
            continue;
        }
        if (a[i] == a[i-1]) {
            total_cover[i] = lcnt[i];
            continue;
        }
        ll both = total_cover[i-1] - (i-rcnt[i-1]);
        total_cover[i] = lcnt[i] + both;
    }

    vector<ll> pfx(n, 0);
    for(int i = 0; i < n; i++) {
        pfx[i] += lcnt[i];
        if (i > 0) {
            pfx[i] += pfx[i-1];
        }
    }

    for(int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        if (lcnt[l] > (r-l)) {
            cout << (r-l+1)*(r-l+2)/2 << endl;
            continue;
        }
        ll total = pfx[r];
        if (l != 0) {
            total -= pfx[l-1];
        }
        if (r != n-1) {
            total -= total_cover[r+1];
            total += lcnt[r+1];
        }
        cout << total << endl;
    }
    return 0;
}