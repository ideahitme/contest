#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int mex = 1e9;

	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		if (r - l < mex) {
			mex = r - l;
		}
	}
	mex++;
	cout << mex << endl;
	int j = 0;
	for(int i = 0; i < n; i++){
		if (j == mex) {
			j = 0;
		}
		a[i] = j;
		cout << a[i] << " ";
		j++;
	}
	cout << endl;
	return 0;
}


