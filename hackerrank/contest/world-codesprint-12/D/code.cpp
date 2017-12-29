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
const ll MOD = 1e9;

const int MAX = - 1 + (1<<30) + (1<<30);
const int MIN = -(1<<31);
const ll lMAX = -1LL + (1LL<<62) + (1LL<<62);
const ll lMIN = -(1LL<<63);

class SegTree
{
private:
    vector<vector<int>> tree;
    vector<int> lazy;
    int orig_len = 0;
    void makeTree(int cur_pos, int l, int r, const vector<int> &arr){
        if (l >= r) {
            if (arr[l] < 40)  {
                tree[cur_pos][arr[l]] = 1;
            }
            return;
        }
        int mid = (l+r)/2;
        makeTree(2*cur_pos+1, l, mid, arr);
        makeTree(2*cur_pos+2, mid+1, r, arr);
        for(int i = 0; i < 40; i++) {
            tree[cur_pos][i] = tree[2*cur_pos+1][i] + tree[2*cur_pos+2][i];
        }
    }
    vector<int> rrmq(int cur_pos, int ql, int qr, int l, int r){ /** recursive rmq range minimum query */
        if (l > r) return vector<int>(40, 0);
        if (lazy[cur_pos] != 0){
            for (int i = 39; i > -1; i--) {
                if (i - lazy[cur_pos] < 0 || i - lazy[cur_pos] > 39) {
                    tree[cur_pos][i] = 0;
                    continue;
                }
                tree[cur_pos][i] = tree[cur_pos][i-lazy[cur_pos]];
            };
            if (l < r){
                lazy[2*cur_pos+1] += lazy[cur_pos];
                lazy[2*cur_pos+2] += lazy[cur_pos];
            }
            lazy[cur_pos] = 0;
        }
        if (ql <= l && qr >= r){ //total overlap
            return tree[cur_pos];
        }
        if (ql > r || qr < l){ //no overlap
            return vector<int>(40, 0);
        }
        //partial overlap case
        int mid = (l+r)/2;
        vector<int> lm = rrmq(2*cur_pos+1, ql, qr, l, mid);
        vector<int> rm = rrmq(2*cur_pos+2, ql, qr, mid+1, r);
        vector<int> answer(40, 0);
        for(int i = 0; i < 40; i++) {
            answer[i] = lm[i] + rm[i];
        }
        return answer;
    }
    void rupd(int cur_pos, int ql, int qr, int l, int r, int x){ /** range update */
        if (l > r) return;
        if (lazy[cur_pos] != 0){
            for (int i = 39; i > -1; i--) {
                if (i - lazy[cur_pos] < 0 || i - lazy[cur_pos] > 39) {
                    tree[cur_pos][i] = 0;
                    continue;
                }
                tree[cur_pos][i] = tree[cur_pos][i-lazy[cur_pos]];
            };
            if (l < r){ //not a leaf
                lazy[2*cur_pos+1] += lazy[cur_pos];
                lazy[2*cur_pos+2] += lazy[cur_pos];
            }
            lazy[cur_pos] = 0;
        }
        //no overlap
        if (qr < l || ql > r){
            return;
        }
        if (ql <= l && qr >= r){ //total overlap
            for (int i = 39; i > -1; i--) {
                if (i - x < 0 || i - x > 39) {
                    tree[cur_pos][i] = 0;
                    continue;
                }
                tree[cur_pos][i] = tree[cur_pos][i-x];
            };
            if (l < r){
                lazy[2*cur_pos+1] += x;
                lazy[2*cur_pos+2] += x;
            }
            return;
        }
        int mid = (l+r)/2;
        rupd(2*cur_pos+1, ql, qr, l, mid, x);
        rupd(2*cur_pos+2, ql, qr, mid+1, r, x);
        for(int i = 0; i < 40; i++) {
            tree[cur_pos][i] = tree[2*cur_pos+1][i] + tree[2*cur_pos+2][i];
        }
    }
    void rset(int cur_pos, int pos, int l, int r, int x){ /** range update */
        if (l > r) return;
        if (lazy[cur_pos] != 0){
            for (int i = 39; i > -1; i--) {
                if (i - lazy[cur_pos] < 0 || i - lazy[cur_pos] > 39) {
                    tree[cur_pos][i] = 0;
                    continue;
                }
                tree[cur_pos][i] = tree[cur_pos][i-lazy[cur_pos]];
            };
            if (l < r){ //not a leaf
                lazy[2*cur_pos+1] += lazy[cur_pos];
                lazy[2*cur_pos+2] += lazy[cur_pos];
            }
            lazy[cur_pos] = 0;
        }
        //no overlap
        if (pos < l || pos > r){
            return;
        }
        if (pos == l && pos == r){ //total overlap
            for (int i = 39; i > -1; i--) {
                if (i == x) {
                    tree[cur_pos][i] = 1;
                    continue;
                }
                tree[cur_pos][i] = 0;
            };
            return;
        }
        int mid = (l+r)/2;
        rset(2*cur_pos+1, pos, l, mid, x);
        rset(2*cur_pos+2, pos, mid+1, r, x);
        for(int i = 0; i < 40; i++) {
            tree[cur_pos][i] = tree[2*cur_pos+1][i] + tree[2*cur_pos+2][i];
        }
    }
public:
    SegTree(const vector<int> &arr){
        int n = 2*(1 << static_cast<int>(ceil(log2(arr.size()))))-1;
        tree.resize(n, vector<int>(40, 0));
        lazy.resize(n, 0);
        orig_len = arr.size();
        makeTree(0, 0, arr.size()-1, arr);
    };
    ~SegTree(){

    }
    vector<int> rmq(int l, int r){
        return rrmq(0, l, r, 0, orig_len-1);
    }
    void inc(int l, int r, int x){
        rupd(0, l, r, 0, orig_len-1, x);
    }
    void set(int i, int x) {
        rset(0, i, 0, orig_len-1, x);
    }
};

int main()
{
	ios::sync_with_stdio(false);
    vector<ll> fact(40, 1);
    fact[0] = 0;
    ll total = 1;
    for(int i = 1; i < 40; i++) {
        total *= i;
        total %= MOD;
        fact[i] = total;
    }
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegTree st(a);
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            st.inc(l, r, 1);
        }
        if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            vector<int> x = st.rmq(l, r);
            ll total = 0;
            for(int i = 0; i < 40; i++) {
                total += fact[i]*static_cast<ll>(x[i]);
                total %= MOD;
            }
            cout << total << endl;
        }
        if (t == 3) {
            int i, v;
            cin >> i >> v;
            i--;
            st.set(i,v);
        }
    }
	return 0;
}