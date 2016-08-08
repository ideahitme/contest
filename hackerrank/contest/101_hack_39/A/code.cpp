#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e9;
const ll lMAX = 1e15;
const double dMAX = static_cast<double>(1e15);

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> count(101);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		count[x]++;
	}
	int max = 0;
	for(int i = 0; i < 101; i++){
		if (count[i] > max) max = count[i];
	}
	cout << (n-max) << endl;
	return 0;
}
