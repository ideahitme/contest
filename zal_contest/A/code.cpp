#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

bool okay(int i, int j, int n){
	return (i < n) && (i >= 0) && (j <= n-1) && (j >= 0);
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int _t = 0; _t < t; _t++){
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(n));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		bool g = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if (a[i][j] == 0) g = true;
				if (okay(i,j+1,n)){
					g = g || (a[i][j] == a[i][j+1]);					
				}
				if (okay(i+1,j,n)){
					g = g || (a[i][j] == a[i+1][j]);					
				}
			}
		}
		if (g){
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

