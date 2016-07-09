#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int total = 0;
	vector<int> luck;
	for(int i = 0; i < n; i++){
		int l, t;
		cin >> l >> t;
		if (t == 0) total += l;
		else luck.push_back(l);
	}
	sort(luck.begin(), luck.end());
	total += accumulate(luck.begin(), luck.end(), 0);
	for(int i = 0; i < luck.size()-k; i++){
		total -= 2 * luck[i];
	}
	cout << total << endl;
	return 0;
}
