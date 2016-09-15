#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int x = m % n;
	if (x == 0) cout << 0;
	else cout << (n-x) << endl;
	return 0;
}
