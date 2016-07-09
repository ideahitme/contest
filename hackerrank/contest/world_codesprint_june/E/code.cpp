#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

ll solution(string top, string bottom, string rtop, string rbottom){
	unordered_map<string, int> vals;
	int n = top.length();
	string top_left_diag = "";
	string bottom_left_diag  = "";
	for(int i = 0; i < n; i++){
		string x;
		if (i % 2 == 0) { 
			top_left_diag += top[i]; top_left_diag += bottom[i]; 
			x = top_left_diag;
			if (i < n-1) {
				x += bottom.substr(i+1, n-i-1);
				x += rtop.substr(0, n-i-1);
			}
			string y = x;
			reverse(y.begin(), y.end());
			vals[x] = 1;
			vals[y] = 1;
		}
		else { 
			top_left_diag += bottom[i]; top_left_diag += top[i]; 
			x = top_left_diag;
			if (i < n-1) {
				x += top.substr(i+1, n-i-1);
				x += rbottom.substr(0, n-i-1);
			}
			string y = x;
			reverse(y.begin(), y.end());
			vals[x] = 1;
			vals[y] = 1;
		}
		if (i % 2 == 1) { 
			bottom_left_diag += top[i]; bottom_left_diag += bottom[i]; 
			x = bottom_left_diag;
			if (i < n-1) {
				x += bottom.substr(i+1, n-i-1);
				x += rtop.substr(0, n-i-1);
			}
			string y = x;
			reverse(y.begin(), y.end());
			vals[x] = 1;
			vals[y] = 1;

		}
		else { 
			bottom_left_diag += bottom[i];bottom_left_diag += top[i]; 
			x = bottom_left_diag;
			if (i < n-1) {
				x += top.substr(i+1, n-i-1);
				x += rbottom.substr(0, n-i-1);
			}
			string y = x;
			reverse(y.begin(), y.end());
			vals[x] = 1;
			vals[y] = 1;
		}
	}	
	string top_right_diag = "";
	string bottom_right_diag  = "";
	for(int i = 0; i < n; i++){
		string x;
		if (i % 2 == 0) { 
			top_right_diag += rtop[i]; top_right_diag += rbottom[i]; 
			x = top_right_diag;
			if (i < n-1) {
				x += rbottom.substr(i+1, n-i-1);
				x += top.substr(0, n-i-1);
			}
			string y = x;
			reverse(y.begin(), y.end());
			vals[x] = 1;
			vals[y] = 1;
		}
		else { 
			top_right_diag += rbottom[i]; top_right_diag += rtop[i]; 
			x = top_right_diag;
			if (i < n-1) {
				x += rtop.substr(i+1, n-i-1);
				x += bottom.substr(0, n-i-1);
			}
			string y = x;
			reverse(y.begin(), y.end());
			vals[x] = 1;
			vals[y] = 1;
		}
		if (i % 2 == 1) { 
			bottom_right_diag += rtop[i]; bottom_right_diag += rbottom[i]; 
			x = bottom_right_diag;
			if (i < n-1) {
				x += rbottom.substr(i+1, n-i-1);
				x += top.substr(0, n-i-1);
			}
			string y = x;
			reverse(y.begin(), y.end());
			vals[x] = 1;
			vals[y] = 1;

		}
		else { 
			bottom_right_diag += rbottom[i];bottom_right_diag += rtop[i]; 
			x = bottom_right_diag;
			if (i < n-1) {
				x += rtop.substr(i+1, n-i-1);
				x += bottom.substr(0, n-i-1);
			}
			string y = x;
			reverse(y.begin(), y.end());
			vals[x] = 1;
			vals[y] = 1;
		}
	}
	for(int i = 0; i < n; i++){
		string x;
		x += top.substr(i, n-i);
		x += rbottom;
		x += top.substr(0, i);
		string y = x;
		reverse(y.begin(), y.end());
		vals[x] = 1;
		vals[y] = 1;
	}	
	for(int i = 0; i < n; i++){
		string x;
		x += bottom.substr(i, n-i);
		x += rtop;
		x += bottom.substr(0, i);
		string y = x;
		reverse(y.begin(), y.end());
		vals[x] = 1;
		vals[y] = 1;
	}
	for(auto it = vals.begin(); it != vals.end(); it++){
		cout << it->first << endl;
	}
	return vals.size();
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int len;
		cin >> len;
		string top;
		string rtop;
		string bottom;
		string rbottom;
		for(int j = 0; j < 2; j++){
			string x;
			cin >> x;
			if (j == 0) {
				top = x;
				string y = x;
				reverse(y.begin(), y.end());
				rtop = y;
			}
			if (j == 1) {
				bottom = x;
				string y = x;
				reverse(y.begin(), y.end());
				rbottom = y;
			}
		}
		cout << solution(top, bottom, rtop, rbottom) << endl;
	}
	return 0;
}