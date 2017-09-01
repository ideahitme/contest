#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	string x,y;
	cin >> x >> y;
	if (x == y) {
		cout << -1 << endl;
	} else {
		cout << max({x.size(), y.size()}) << endl;
	}

	return 0;
}
