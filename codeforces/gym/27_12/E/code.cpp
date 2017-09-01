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

int state = 0; 
/*
0 - normal
1 - looking for b, k is 0
*/
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	vector<pii> actions;
	int k, b;
	int ko, bo;
	ko = 0;
	bo = 0;
	while (true) {
		cout << 0 << " " << ko << " " << bo << endl;
		cout << flush;
		int q;
		cin >> q;
		if (q == -1) {
			k = 0; b = 0;
			break;
		}
		if (q == 0) {
			//k == 0, b == 0
			
		}
		if (q == 1) {

		}
		actions.push_back({ko,bo});
	}
	for(int i = actions.size()-1; i >= 0; i--) {
		k -= actions[i].first;
		b -= actions[i].second;
	}
	cout << 1 << " " << k << " " << b << endl;
	return 0;
}