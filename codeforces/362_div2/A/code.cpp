#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e9;
const ll lMAX = 1e15;
const int PRIME = 1e9+7;

int main(int argc, char const *argv[])
{
	int t,s,x;
	cin >> t >> s >> x;
	if (t > x) {
		cout << "NO" << endl;
		return 0;
	}
	if (t == x){
		cout << "YES" << endl;
		return 0;
	}
	if (t == x+1 && s == 1){
		cout << "YES" << endl;
		return 0;
	}
	if (t == x+2 && s == 2){
		cout << "YES" << endl;
		return 0;
	}
	int diff = x-t;
	if (diff % s == 0 || ((diff-1) % s == 0 && diff > 1)){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	/* code */
	return 0;
}

