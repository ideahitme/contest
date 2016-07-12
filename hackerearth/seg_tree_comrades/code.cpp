#include <algorithm>
#include <iostream>
#include <iomanip>
#include <set>
#include <queue>
#include <cmath>
#include <assert.h>
#include <stack>

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
		tree[cur_pos] = tree[2*cur_pos+1] + tree[2*cur_pos+2];
	}
	int rrmq(int cur_pos, int ql, int qr, int l, int r){ /** recursive rmq range minimum query */
		if (l > r) return 0;
		if (lazy[cur_pos] != -1){
			tree[cur_pos] = lazy[cur_pos]*(r-l+1);
			if (l < r){
				lazy[2*cur_pos+1] = lazy[cur_pos];
				lazy[2*cur_pos+2] = lazy[cur_pos];
			}
			lazy[cur_pos] = -1;
		}
		if (ql <= l && qr >= r){ //total overlap
			return tree[cur_pos];
		}
		if (ql > r || qr < l){ //no overlap
			return 0;
		}
		//partial overlap case
		int mid = (l+r)/2;
		tree[cur_pos] = rrmq(2*cur_pos+1, ql, qr, l, mid) + rrmq(2*cur_pos+2, ql, qr, mid+1, r);
		return tree[cur_pos];
	}
	void rset(int cur_pos, int ql, int qr, int l, int r, int val){
		if (l > r) return;
		if (lazy[cur_pos] != -1){
			tree[cur_pos] = lazy[cur_pos]*(r-l+1);
			if (l < r){
				lazy[2*cur_pos+1] = lazy[cur_pos];
				lazy[2*cur_pos+2] = lazy[cur_pos];
			}
			lazy[cur_pos] = -1;
		}
		if (qr < l || ql > r){
			return;
		}
		if (ql <= l && qr >= r){
			tree[cur_pos] = val*(r-l+1);
			if (l < r){
				lazy[2*cur_pos+1] = val;
				lazy[2*cur_pos+2] = val;
			}
			return;
		}
		int mid = (l+r)/2;
		rset(2*cur_pos+1, ql, qr, l, mid, val);
		rset(2*cur_pos+2, ql, qr, mid+1, r, val);
		tree[cur_pos] = tree[2*cur_pos+1] + tree[2*cur_pos+2];
	}
public:
	SegTree(const vector<int> &arr){
		int n = 2*(1 << static_cast<int>(ceil(log2(arr.size()))))-1;
		tree.resize(n, MAX);
		lazy.resize(n, 1);
		orig_len = arr.size();
		makeTree(0, 0, arr.size()-1, arr);
	};
	~SegTree(){

	}
	int rmq(int l, int r){
		if (l > r) return 0;
		return rrmq(0, l, r, 0, orig_len-1);
	}
	void sleep(int l, int r){
		if (l > r) return;
		rset(0, l, r, 0, orig_len-1, 0);
	}
	void wake(int l, int r){
		if (l > r) return;
		rset(0, l, r, 0, orig_len-1, 1);
	}
	void print(){
		for(auto it: tree){
			cout << it << " ";
		}
		cout << endl;
		for(auto it: lazy){
			cout << it << " ";
		}
		cout << endl;
	}
};

int c = 0;

void explore(
		int cur,
		const vector<vector<int>> &edges,
		vector<int> &pre,
		vector<int> &post
	){	
	pre[cur] = c;
	for(auto it = edges[cur].begin(); it != edges[cur].end(); it++){
		c++;
		explore(*it, edges, pre, post);
	}
	post[cur] = c;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	int root;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (x == 0) root = i;
		else graph[x-1].push_back(i);
	}
	vector<int> pre(n);
	vector<int> post(n);
	vector<int> arr(n, 1);
	SegTree s(arr);
	explore(root, graph, pre, post);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int t, x;
		cin >> t >> x;
		x--;
		if (t == 1){
			s.wake(pre[x]+1, post[x]);
		}
		if (t == 2){
			s.sleep(pre[x]+1, post[x]);
		}
		if (t == 3){
			cout << s.rmq(pre[x]+1, post[x]) << endl;
		}
	}
	return 0;
}
// 6
// 6
// 3
// 0
// 6
// 4
// 6
// 1
// 1
// 0
