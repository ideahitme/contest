#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1e9 + 7;
const int PRIME = 1e9 + 7;



class SegTree
{
private:
	vector<int> tree;
	int orig_len = 0;
	void makeTree(int cur_pos, int l, int r, const vector<int> &arr){
		if (l >= r) {
			tree[cur_pos] = arr[l];
			return; 
		}
		int mid = (l+r)/2;
		makeTree(2*cur_pos+1, l, mid, arr);
		makeTree(2*cur_pos+2, mid+1, r, arr);
		int l_r = tree[2*cur_pos+1]^tree[2*cur_pos+2];
		// int l_mid_r = 
		tree[cur_pos] = min({tree[2*cur_pos+1], tree[2*cur_pos+2]});
	}
	int rrmq(int cur_pos, int ql, int qr, int l, int r){ /** recursive rmq range minimum query */
		if (l > r) return MAX;
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
public:
	SegTree(const vector<int> &arr){
		int n = 2*(1 << static_cast<int>(ceil(log2(arr.size()))))-1;
		tree.resize(n, MAX);
		orig_len = arr.size();
		makeTree(0, 0, arr.size()-1, arr);
	};
	~SegTree(){

	}
	int rmq(int l, int r){
		assert(l <= r);
		return rrmq(0, l, r, 0, orig_len-1);
	}
	void print(){
		for(auto it: tree){
			cout << it << " ";
		}
		cout << endl;
	}
};


int xor_range(const vector<int> &pxor, int l, int r){
	if (l == 0) return pxor[r];
	return pxor[r]^pxor[l-1];
}

int xor_range_unique(){
	return 0;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> pxor(n);
	SegTree t(a);
	int txor = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		txor = txor ^ a[i];
		pxor[i] = txor;
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int l,r;
		cin >> l >> r;
		l--;r--;
		int all_xor = xor_range(pxor, l, r);
		int uniq_xor = xor_range_unique();
		cout << (all_xor ^ uniq_xor) << endl;
	}

	return 0;
}
