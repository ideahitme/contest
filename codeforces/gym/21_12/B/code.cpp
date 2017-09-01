#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <set>
#include <queue>
#include <cmath>
#include <assert.h>
#include <map>

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
		tree[cur_pos] = max({tree[2*cur_pos+1], tree[2*cur_pos+2]});
	}
	int rrmq(int cur_pos, int ql, int qr, int l, int r){ /** recursive rmq range maximum query */
		if (l > r) return -MAX;
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
			return -MAX;
		}
		//partial overlap case
		int mid = (l+r)/2;
		return max({rrmq(2*cur_pos+1, ql, qr, l, mid), rrmq(2*cur_pos+2, ql, qr, mid+1, r) });
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
		tree[cur_pos] = max({tree[2*cur_pos+1], tree[2*cur_pos+2]});
	}
public:
	SegTree(const vector<int> &arr){
		int n = 2*(1 << static_cast<int>(ceil(log2(arr.size()))))-1;
		tree.resize(n, -MAX);
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
};

int main(int argc, char const *argv[])
{
	ifstream infile("different.in");
	ofstream outfile("different.out");
	int n, m, k;
	infile >> n >> m >> k;
	vector<int> x(n);
 	map<int, set<int>> mset;
	for(int i = 0; i < n; i++){
		infile >> x[i];
		mset[x[i]].insert(i);
	}

	vector<int> a;
 	
 	map<int, int> cnt;
	for(int i = 0; i < k; i++){
		if (cnt.find(x[i]) == cnt.end()){
			cnt[x[i]] = 0;
		}		
		cnt[x[i]]++;
	}
	a.push_back(cnt.size());
	for(int i = k; i < n; i++){
		cnt[x[i-k]]--;
		if (cnt[x[i-k]] == 0){
			cnt.erase(cnt.find(x[i-k]));
		}
		if (cnt.find(x[i]) == cnt.end()){
			cnt[x[i]] = 0;
		}
		cnt[x[i]]++;
		a.push_back(cnt.size());
	}


	SegTree tree = SegTree(a);

	for(int i = 0; i < m; i++) {
		int c;
		infile >> c;

		if (c == 1){
			int i, newc;
			infile >> i >> newc;
			i--;
			int oldc = x[i];
			x[i] = newc;

			int oldl = -1, oldr = i+k;
			auto itl = mset[oldc].lower_bound(i);
			auto itr = mset[oldc].upper_bound(i);
			if (itl != mset[oldc].begin()){
				itl--;
				oldl = *itl;
			}
			if (itr != mset[oldc].end()){
				oldr = *itr;
			}
			oldl = max({-1, oldl, i-k});
			oldr = min({i+k, n, oldr});
			if (oldr-oldl > k) tree.inc(oldl+1, oldr-k,-1);

			int newl = -1, newr = i+k;
			itl = mset[newc].lower_bound(i);
			itr = mset[newc].upper_bound(i);
			if (itl != mset[newc].begin()){
				itl--;
				newl = *itl;
			}
			if (itr != mset[newc].end()){
				newr = *itr;
			}
			newl = max({-1, newl, i-k});
			newr = min({i+k, n, newr});
			if (newr-newl > k) tree.inc(newl+1,newr-k,1);

			mset[oldc].erase(mset[oldc].find(i));
			mset[newc].insert(i);
		}
		if (c == 2){
			int l, r;
			infile >> l >> r;
			l--;r--;
			outfile << tree.rmq(l, r-k+1) << endl;
		}
	}

	return 0;
}