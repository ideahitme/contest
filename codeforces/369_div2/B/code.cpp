#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

const int MAX = 1e9+7;
const int PRIME = 1e9+9;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n, 0));
	int xi, xj;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if (a[i][j] == 0){
				xi = i;
				xj = j;
			}
		}
	}
	if (n == 1){
		cout << 1 << endl;
		return 0;
	}
	ll xsum = 0;
	for(int j = 0; j < n; j++){
		if (xi == 0){
			xsum += a[1][j];
		}
		else xsum += a[0][j];
	}
	ll wsum = 0;
	for(int j = 0; j < n; j++){
		wsum += a[xi][j];
	}
	a[xi][xj] = xsum - wsum;
	if (a[xi][xj] <= 0) {
		cout << -1 << endl;
		return 0;
	}
	bool correct = true;
	for(int i = 0; i < n; i++){
		ll rsum = 0;
		for(int j = 0; j < n; j++){
			rsum += a[i][j];
		}
		correct = correct && (rsum == xsum);
	}	
	for(int i = 0; i < n; i++){
		ll rsum = 0;
		for(int j = 0; j < n; j++){
			rsum += a[j][i];
		}
		correct = correct && (rsum == xsum);
	}
	ll dsum = 0;
	for(int i = 0; i < n; i++){
		dsum += a[i][i];
	}
	correct = correct && (dsum == xsum);
	dsum = 0;
	for(int i = 0; i < n; i++){
		dsum += a[i][n-i-1];
	}
	correct = correct && (dsum == xsum);	
	if (correct) {
		cout << a[xi][xj] << endl;
	}
	else cout << -1 << endl;
	return 0;
}

