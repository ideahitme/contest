#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e9+7;
const int MIN = -1e9;
const int PRIME = 1e9+7;
const ll lMAX = 1e15;
const ll lMIN = -1e15;

bool is_valid(int x, int y){
	if (x == 3 && y == 1) return true;
	if (x >= 0 && x <= 2 && y >= 0 && y <= 2) return true;
	return false;
}

bool check_shift(vector<pair<int,int>> &vals, int shift_x, int shift_y){
	bool val = true;
	for(int i = 0; i < vals.size(); i++){
		pii p = vals[i];
		int x = p.first;
		int y = p.second;
		val = val && is_valid(x-shift_x,y-shift_y);
	}
	return val;
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);

	unordered_map<int, pair<int,int>> m;
	m[0] = {3,1};
	m[1] = {0,0};
	m[2] = {0,1};
	m[3] = {0,2};
	m[4] = {1,0};
	m[5] = {1,1};
	m[6] = {1,2};
	m[7] = {2,0};
	m[8] = {2,1};
	m[9] = {2,2};
	/* code */
	int n;
	cin >> n;
	string x;
	cin >> x;
	vector<pair<int,int>> vals;
	for(int i = 0; i < x.length(); i++){
		char t = x[i];
		int num = static_cast<int>(t)-48;
		vals.push_back(m[num]);
	}
	if (check_shift(vals,-1, 0) || check_shift(vals,1, 0) || check_shift(vals,0, -1) || check_shift(vals, 0, 1)){
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;
	return 0;
}
