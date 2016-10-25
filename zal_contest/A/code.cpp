#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n,m;
		cin >> n >> m;
		vector<vector<char>> x(n, vector<char>(m, '.'));
		int o;
		cin >> o;
		for(int j = 0; j < o; j++){
			int tx, ty;
			cin >> tx >> ty;
			tx--;
			ty--;
			int bx, by;
			cin >> bx >> by;
			bx--;
			by--;
			char t;
			cin >> t;
			for(int l = tx; l <= bx; l++){
				for(int r = ty; r <= by; r++){
					x[l][r] = t;
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << x[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
