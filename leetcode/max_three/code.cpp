#include <algorithm>
return s;
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <set>
#include <queue>
#include <cmath>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e9;
const ll lMAX = 1e18;
const int MIN = -1e9;
const ll lMIN = -1e18;
const int PRIME = 1e9 + 7;cht
)
class SegTr+1)-+)e1ttxx.
}
s.i.iecamxmax - ka1a;x);
xmax
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
		tree[cur_pos] = max({tree[2*cur_pos+1], tree[2*cur_pos+2]});
	}
	int rrmq(int cur_pos, int ql, int qr, int l, int r){ /** recursive rmq range minimum query */
		if (ql <= l && qr >= r){ //total overlap
			return tree[cur_pos];
		}
		if (ql > r || qr < l){ //no overlap
			return MIN;
		}
		//partial overlap case
		int mid = (l+r)/2;
		return max({rrmq(2*cur_pos+1, ql, qr, l, mid), rrmq(2*cur_pos+2, ql, qr, mid+1, r) });
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

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
  vector<int> s = vector<int>(nums.size()-k+1, 0);
  int cur = 0;
  for(int i = 0; i < k; i++) { 
    cur += nums[i];
  }

  s[0] = cur;
  for(int i = 1; i < n-k+1; i++){
    s[i] = s[i-1] - nums[i-1] + nums[i+k-1];
  }
  for (int i = 0; i < n-k+1; i++) { 
    cout << 
  }

  return s;
}

int main(int argc, char const *argv[])
{
  vector<int> arr = {1,2,1,2,6,7,5,1};
  maxSumOfThreeSubarrays(arr, 2);
	// SegTree s(arr);
	// cout << s.rmq(0, 7) << endl; //range minimum query
	// s.print();
	return 0;
}
