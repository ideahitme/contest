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

/** segment tree to update single element + 
count number of even and count number of odd numbers in range l,r */
class SegTree
{
private:
	vector<pii> tree;
	int orig_len = 0;
	void makeTree(int cur_pos, int l, int r, const vector<int> &arr){
		if (l >= r) {
			if (arr[l] % 2 == 0){
				tree[cur_pos] = {1, 0};
			} else {
				tree[cur_pos] = {0, 1};
			}
			return; 
		}
		int mid = (l+r)/2;
		makeTree(2*cur_pos+1, l, mid, arr);
		makeTree(2*cur_pos+2, mid+1, r, arr);
		tree[cur_pos] = {tree[2*cur_pos+1].first + tree[2*cur_pos+2].first, tree[2*cur_pos+1].second + tree[2*cur_pos+2].second};
	}
	void upd(int cur_pos, int index, int l, int r, int val){
		if (l > r) return;
		if (l > index || r < index) return;
		if (l == r){
			if (tree[cur_pos].first == 1 && val % 2 == 1){
				tree[cur_pos].first = 0;
				tree[cur_pos].second = 1;
			} 
			if (tree[cur_pos].first == 0 && val % 2 == 0){
				tree[cur_pos].first = 1;
				tree[cur_pos].second = 0;
			}
			return;
		}
		else {
			int mid = (l+r)/2;
			upd(2*cur_pos+1, index, l, mid, val);
			upd(2*cur_pos+2, index, mid+1, r, val);
			tree[cur_pos] = {tree[2*cur_pos+1].first + tree[2*cur_pos+2].first, tree[2*cur_pos+1].second + tree[2*cur_pos+2].second};
		}
	}
	int range_even(int cur_pos, int ql, int qr, int l, int r){
		if (ql > r || qr < l){ //no overlap
			return 0;
		}
		if (ql <= l && qr >= r){
			return tree[cur_pos].first;
		}
		int mid = (l+r)/2;
		return range_even(2*cur_pos+1, ql, qr, l, mid) + range_even(2*cur_pos+2, ql, qr, mid+1, r);
	}
	int range_odd(int cur_pos, int ql, int qr, int l, int r){
		if (ql > r || qr < l){ //no overlap
			return 0;
		}
		if (ql <= l && qr >= r){
			return tree[cur_pos].second;
		}
		int mid = (l+r)/2;
		return range_odd(2*cur_pos+1, ql, qr, l, mid) + range_odd(2*cur_pos+2, ql, qr, mid+1, r);
	}
public:
	SegTree(const vector<int> &arr){
		int n = 2*(1 << static_cast<int>(ceil(log2(arr.size()))))-1;
		tree.resize(n, {0, 0});
		orig_len = arr.size();
		makeTree(0, 0, arr.size()-1, arr);
	};
	~SegTree(){

	}
	void update(int x, int val){
		upd(0, x, 0, orig_len-1, val);
	}
	void print(){
		for(auto it: tree){
			cout << it.first << " " << it.second << endl;
		}
	}
	int even_query(int x, int y){
		return range_even(0, x, y, 0, orig_len-1);
	}
	int odd_query(int x, int y){
		return range_odd(0, x, y, 0, orig_len-1);
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
		int t, x,y;
		cin >> t >> x >> y;
		if (t == 0){ //update an element at x to value y
			x--;
			s.update(x, y);
		}
		if (t == 1){ //number of even numbers in range x to y
			x--;
			y--;
			cout << s.even_query(x, y) << endl;
		}
		if (t == 2){ //number of odd numbers in range x to y
			x--;
			y--;
			cout << s.odd_query(x, y) << endl;
		}
	}
	return 0;
}
