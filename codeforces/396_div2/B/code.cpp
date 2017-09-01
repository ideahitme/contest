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
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (n < 3) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 0; i < n-2; i++){
		if (a[i] + a[i+1] > a[i+2]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
