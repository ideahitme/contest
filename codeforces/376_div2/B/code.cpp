#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int PRIME = 1e9+7;
const int MAX = 1e9+10;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		if (a[i] % 2 == 0 && a[i] > 0) a[i] = 2;
		else if (a[i] % 2 == 1) a[i] = 1;
	}
	bool pos = true;
	for(int j = 0; j < n; j++){
		if (a[j] < 0) { 
			pos = false;
			break;
		}
		if (a[j] % 2 == 0) continue;
		else {
			if (j == n-1) pos = false;
			else a[j+1]--;
		}
	}
	if (pos) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}