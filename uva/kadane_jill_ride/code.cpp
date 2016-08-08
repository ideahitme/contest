// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=448
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/**
 * find maximum subarray inside the array
 */

typedef long long ll;

/**
 * maximum subarray inside array, l, r will point to beginning and end of the subarray
 * @param  a [description]
 * @param  l [description]
 * @param  r [description]
 * @return   [description]
 */

ll kadane(const vector<int> &a, int &l, int &r){
	ll max_number = static_cast<ll>(a[0]); //maximum number in array
	ll max_so_far = 0; //maximum subarry so far ending at index i
	ll answer = 0;
	int _l = 0;
	int _r = 0;
	int _mxptr = 0; //index to maximum element
 	for(int i = 0; i < a.size(); i++){
		if (max_so_far + (ll)a[i] > max_so_far){
			_r = i;
		}
		if (max_so_far + (ll)a[i] < 0){
			_l = i+1;
		}
		max_so_far = max({max_so_far + (ll)a[i], 0ll});
		if (max_number < (ll)a[i]){
			max_number = (ll)a[i];	
			_mxptr = i;
		}	
		if (answer <= max_so_far){
			if (answer < max_so_far || _r - _l > r - l){
				l = _l;
				r = _r;
			}
			answer = max_so_far;
		}
	}
	if (max_number < 0) {
		l = _mxptr;
		r = _mxptr;
		return max_number;
	}
	return answer;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int stops;
		cin >> stops;
		vector<int> a(stops-1);
		for(int j = 0; j < stops-1; j++){
			cin >> a[j];
		}
		int l = 0, r = 0;
		ll res = kadane(a,l,r);
		if (res > 0){
			cout << "The nicest part of route " << (i+1) << " is between stops " << (l+1) << " and " << (r+2) << endl;
		} else {
			cout << "Route " << (i+1) << " has no nice parts" << endl;
		}

	}
	return 0;
}
