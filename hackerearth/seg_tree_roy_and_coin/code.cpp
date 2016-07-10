// https://www.hackerearth.com/problem/algorithm/roy-and-coin-boxes-1
// 
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <set>
#include <queue>
#include <cmath>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1e9;
const ll lMAX = 1e18;
const int PRIME = 1e9+7;

class SegTree
{
private:
	vector<int> tree;
	vector<int> lazy;
	vector<int> count;
	int orig_len = 0;
	void makeTree(int cur_pos, int l, int r, const vector<int> &arr){
		if (l >= r) {
			tree[cur_pos] = arr[l];
			return; 
		}
		int mid = (l+r)/2;
		makeTree(2*cur_pos+1, l, mid, arr);
		makeTree(2*cur_pos+2, mid+1, r, arr);
		tree[cur_pos] = min({tree[2*cur_pos+1], tree[2*cur_pos+2]});
	}
	int rq(int cur_pos, int l, int r, int x){ /** recursive rmq range minimum query */
		if (l > r) return MAX;
		if (lazy[cur_pos] != 0){
			tree[cur_pos] += lazy[cur_pos];
			if (l < r){
				lazy[2*cur_pos+1] += lazy[cur_pos];
				lazy[2*cur_pos+2] += lazy[cur_pos];
			}
			lazy[cur_pos] = 0;
		}
		if (tree[cur_pos] >= x){
			return r-l+1;
		}
		if (l == r){
			return (tree[cur_pos] >= x ? 1: 0);
		}
		//partial overlap case
		int mid = (l+r)/2;
		return rq(2*cur_pos+1, l, mid, x) + rq(2*cur_pos+2, mid+1, r, x) ;
	}
	void rupd(int cur_pos, int ql, int qr, int l, int r, int x){ /** range update */
		if (l > r) return;
		if (lazy[cur_pos] != 0){
			tree[cur_pos] += lazy[cur_pos];
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
			tree[cur_pos] += x;
			if (l < r){
				lazy[2*cur_pos+1] += x;
				lazy[2*cur_pos+2] += x;
			}
			return;
		}
		int mid = (l+r)/2;
		rupd(2*cur_pos+1, ql, qr, l, mid, x);
		rupd(2*cur_pos+2, ql, qr, mid+1, r, x);
		tree[cur_pos] = min({tree[2*cur_pos+1], tree[2*cur_pos+2]});
	}
	void rapp(int cur_pos, int l, int r){
		if (l > r) return;
		if (lazy[cur_pos] != 0){
			tree[cur_pos] += lazy[cur_pos];
			if (l < r){ //not a leaf
				lazy[2*cur_pos+1] += lazy[cur_pos];
				lazy[2*cur_pos+2] += lazy[cur_pos];
			}
			lazy[cur_pos] = 0;
		}
		if (l == r) {
			if (tree[cur_pos] < MAX) count[tree[cur_pos]]++;	
			return;
		} 
		int mid = (l+r)/2;
		rapp(2*cur_pos+1, l, mid);
		rapp(2*cur_pos+2, mid+1, r);
		tree[cur_pos] = min({tree[2*cur_pos+1], tree[2*cur_pos+2]});
	}
public:
	SegTree(const vector<int> &arr){
		int n = 2*(1 << static_cast<int>(ceil(log2(arr.size()))))-1;
		tree.resize(n, MAX);
		lazy.resize(n, 0);
		orig_len = arr.size();
		makeTree(0, 0, arr.size()-1, arr);
	};
	~SegTree(){

	}
	//apply all lazy props
	void apply(int len){
		count.resize(len+1, 0);
		rapp(0, 0, orig_len-1);
		for(int i = 0; i < len+1; i++){
			if (i > 0) count[i] += count[i-1];
		}
	}
	int ans(int x){
		if (x == 0) return orig_len;
		if (x >= count.size()) return 0;
		return orig_len - count[x-1];
	}
	int q(int x){  //returns how many elements are at least x
		return rq(0, 0, orig_len-1, x);
	}
	void inc(int l, int r, int x){
		assert(l <= r);
		rupd(0, l, r, 0, orig_len-1, x);
	}
	void print(){
		for(auto it: tree){
			cout << it << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n, 0);
	SegTree s(arr);
	for(int i = 0; i < m; i++){
		int l,r;
		cin >> l >> r;
		l--; r--;
		s.inc(l,r,1);
	}
	int q;
	cin >> q;
	s.apply(m);
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		cout << s.ans(x) << endl;
	}
	return 0;
}
