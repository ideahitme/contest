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
	int rrmq(int cur_pos, int ql, int qr, int l, int r){ /** recursive rmq range minimum query */
		if (l > r) return MAX;
		if (lazy[cur_pos] != 0){
			tree[cur_pos] += lazy[cur_pos];
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
			return MAX;
		}
		//partial overlap case
		int mid = (l+r)/2;
		return min({rrmq(2*cur_pos+1, ql, qr, l, mid), rrmq(2*cur_pos+2, ql, qr, mid+1, r) });
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
			cout << tree[cur_pos] << " ";
			return;
		} 
		int mid = (l+r)/2;
		rapp(2*cur_pos+1, l, mid);
		rapp(2*cur_pos+2, mid+1, r);
		tree[cur_pos] = min({tree[2*cur_pos+1], tree[2*cur_pos+2]});
	}	
	void rhit(int cur_pos, int l, int r, int x){ /** range update */
		if (l > r) return;
		if (lazy[cur_pos] != 0){
			tree[cur_pos] += lazy[cur_pos];
			if (l < r){ //not a leaf
				lazy[2*cur_pos+1] += lazy[cur_pos];
				lazy[2*cur_pos+2] += lazy[cur_pos];
			}
			lazy[cur_pos] = 0;
		}
		if (l == r){
			if (tree[cur_pos] > x) tree[cur_pos]--;
		}
		else {
			if (tree[cur_pos] > x){
				tree[cur_pos] -= 1;
				lazy[2*cur_pos+1] -= 1;
				lazy[2*cur_pos+2] -= 1;				
			}
			else {
				int mid = (l+r)/2;
				rhit(2*cur_pos+1, l, mid, x);
				rhit(2*cur_pos+2, mid+1, r, x);
				tree[cur_pos] = min({tree[2*cur_pos+1], tree[2*cur_pos+2]});
			}
		}

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
	int rmq(int l, int r){
		assert(l <= r);
		return rrmq(0, l, r, 0, orig_len-1);
	}
	void inc(int l, int r, int x){
		assert(l <= r);
		rupd(0, l, r, 0, orig_len-1, x);
	}
	void hit(int x){
		rhit(0, 0, orig_len-1, x);
	}
	void print(){
		rapp(0, 0, orig_len-1);
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	SegTree s(arr);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		s.hit(x);
	}
	s.print();
	return 0;
}
