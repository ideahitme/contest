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
	vector<vector<int>> tree;
	vector<int> lazy;
	int orig_len = 0;
	void makeTree(int cur_pos, int l, int r){
		if (l >= r) {
			tree[cur_pos][0] = 1;
			return; 
		}
		int mid = (l+r)/2;
		makeTree(2*cur_pos+1, l, mid);
		makeTree(2*cur_pos+2, mid+1, r);
		for(int i = 0; i < 4; i++){
			tree[cur_pos][i] = tree[2*cur_pos+1][i] + tree[2*cur_pos+2][i];
		}
	}
	void rquery(int cur_pos, int ql, int qr, int l, int r, vector<int> &res){ /** recursive rmq range minimum query */
		if (l > r) return;
		if (lazy[cur_pos]%4 != 0){
			lazy[cur_pos] = lazy[cur_pos] % 4;
 			vector<int> old(tree[cur_pos]);
			for(int i = 0; i < 4; i++){
				tree[cur_pos][i] = old[((i+lazy[cur_pos])%4+4)%4];
			}
			if (l < r){
				lazy[2*cur_pos+1] += lazy[cur_pos];
				lazy[2*cur_pos+2] += lazy[cur_pos];
			}
			lazy[cur_pos] = 0;
		}
		if (ql <= l && qr >= r){ //total overlap
			for(int i = 0; i < 4; i++){
				res[i] += tree[cur_pos][i];
			}
			return;
		}
		if (ql > r || qr < l){ //no overlap
			return;
		}
		//partial overlap case
		int mid = (l+r)/2;
		rquery(2*cur_pos+1, ql, qr, l, mid, res);
	 	rquery(2*cur_pos+2, ql, qr, mid+1, r, res);
	}
	void rupd(int cur_pos, int ql, int qr, int l, int r, int x){ /** range update */
		if (l > r) return;
		if (lazy[cur_pos] != 0){
			lazy[cur_pos] = lazy[cur_pos] % 4;
 			vector<int> old(tree[cur_pos]);
			for(int i = 0; i < 4; i++){
				tree[cur_pos][i] = old[((i+lazy[cur_pos])%4+4)%4];
			}
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
 			vector<int> old(tree[cur_pos]);
			for(int i = 0; i < 4; i++){
				tree[cur_pos][i] = old[((i+x)%4+4)%4];
			}
			if (l < r){
				lazy[2*cur_pos+1] += x;
				lazy[2*cur_pos+2] += x;
			}
			return;
		}
		int mid = (l+r)/2;
		rupd(2*cur_pos+1, ql, qr, l, mid, x);
		rupd(2*cur_pos+2, ql, qr, mid+1, r, x);
		for(int i = 0; i < 4; i++){
			tree[cur_pos][i] = tree[2*cur_pos+1][i] + tree[2*cur_pos+2][i];
		}
	}
public:
	SegTree(int len){
		orig_len = len;
		int n = 2*(1 << static_cast<int>(ceil(log2(orig_len))))-1;
		tree.resize(n, vector<int>(4, 0));
		lazy.resize(n, 0);
		makeTree(0, 0, orig_len-1);
	};
	~SegTree(){

	}
	void query(int l, int r, vector<int> &res){
		assert(l <= r);
		rquery(0, l, r, 0, orig_len-1, res);
	}
	void rotate(int l, int r, int x){
		rupd(0, l, r, 0, orig_len-1, x);
	}
};

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	SegTree s(n);
	for(int i = 0; i < m; i++){
		char t;
		cin >> t;
		if (t == 'C'){
			int l, r, k;
			cin >> l >> r >> k;
			l--;r--;k = k%4;
			s.rotate(l,r,-k);
		}
		if (t == 'A'){
			int l, r, k;
			cin >> l >> r >> k;
			l--;r--;k = k%4;
			s.rotate(l,r,k);
		}
		if (t == 'Q'){
			int l, r;
			cin >> l >> r;
			l--;r--;
			vector<int> res(4,0);
			s.query(l,r,res);
			cout << *max_element(res.begin(), res.end()) << endl;
		}
	}
	return 0;
}
