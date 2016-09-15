#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		int ans = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
		cout << ans << endl;
	}
	return 0;
}