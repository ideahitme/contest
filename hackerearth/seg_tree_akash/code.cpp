#include <algorithm>
#include <iostream>
#include <iomanip>
#include <set>
#include <queue>
#include <cmath>
#include <assert.h>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1e9;
const ll lMAX = 1e18;
const int PRIME = 1e9+7;
int c = 0;
class SegTree
{
private:
	vector<vector<int>> tree;
	int orig_len = 0;
	void makeTree(int cur_pos, int l, int r, string &x){
		if (l >= r) {
			tree[cur_pos][(x[l]-'a')] = 1;
			return; 
		}
		int mid = (l+r)/2;
		makeTree(2*cur_pos+1, l, mid, x);
		makeTree(2*cur_pos+2, mid+1, r, x);
		for(int i = 0; i < 26; i++){
			tree[cur_pos][i] = tree[2*cur_pos+1][i] + tree[2*cur_pos+2][i];
		}
	}
	void bottom_up(){

	}
	void rupd(int pos, char o, char n){
		int cur_pos = 0;
		int l = 0;
		int r = orig_len-1;
		while(l <= r){
			tree[cur_pos][(o-'a')]--;
			tree[cur_pos][(n-'a')]++;
			if (l == r) break;
			int mid = (l+r)/2;
			if (l <= pos && pos <= mid){
				cur_pos = 2*cur_pos+1;
				r = mid;
			}
			else {
				cur_pos = 2*cur_pos+2;
				l = mid+1;
			}
		}
	}
	void rquery(int cur_pos, int ql, int qr, int l, int r, vector<int> &arr){
		if (ql <= l && qr >= r){ //total overlap
			for(int i = 0; i < 26; i++){
				arr[i] += tree[cur_pos][i];
			}
			return;
		}
		if (ql > r || qr < l){ //no overlap
			return;
		}
		//partial overlap case
		int mid = (l+r)/2;
		rquery(2*cur_pos+1, ql, qr, l, mid, arr);
		rquery(2*cur_pos+2, ql, qr, mid+1, r, arr);
	}
public:
	SegTree(string &x){
		int n = 2*(1 << static_cast<int>(ceil(log2(x.length()))))-1;
		tree.resize(n, vector<int>(26, 0));
		orig_len = x.length();
		makeTree(0, 0, x.length()-1, x);
	};
	~SegTree(){

	}
	void print(){
		for(auto ch: tree[0]){
			cout << ch << endl;
		}
	}
	void update(int pos, char o, char n){
		if (n == o) return;
		rupd(pos, o, n);
	}
	void query(int l, int r, vector<int> &arr){
		rquery(0, l, r, 0, orig_len-1, arr);
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	// int n = 1e6;
	// int q = 1e5;
	// string letters = "abcdefghijklmnopqrstuvwxyz";
	// string x(n, 0);
	// int j;
	// for(int i = 0; i < n; i++){
	// 	j = rand() % 26;
	// 	x[i] = letters[j];
	// }
	// SegTree s(x);
	int n, q;
	cin >> n >> q;
	string x;
	cin >> x;
	SegTree s(x);
	for(int i = 0; i < q; i++){
		int t;
		cin >> t;
		if (t == 0){
			int pos;
			char n;
			cin >> pos >> n;
			pos--;
			char o = x[pos];
			x[pos] = n;
			s.update(pos, o, n);
		}
		if (t == 1){
			int l, r, k;
			cin >> l >> r >> k;
			l--;r--;
			if (k > r-l+1){
				cout << "Out of range" << endl;
			}
			else {
				vector<int> arr(26, 0);
				s.query(l, r, arr);
				int so_far = 0;
				for(int i = 0; i < arr.size(); i++){
					// cout << arr[i] << endl;
					so_far+=arr[i];
					if (so_far >= k){
						cout << (char)('a' + i) << endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}
