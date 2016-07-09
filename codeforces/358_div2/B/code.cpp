#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[i] = x;
	}		
	sort(a.begin(), a.end());
	int j = 1;
	for(int i = 0; i < n; i++){
		if (a[i] >= j) j++;
	}
	cout << j << endl;
	return 0;
}
