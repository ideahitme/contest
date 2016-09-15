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
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> c(n);
	vector<vector<int>> p(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	vector<int> cc(c);
	int pmin = 1e9+2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> p[i][j];
			pmin = min({pmin, p[i][j]});
		}
	}
	int total_k = 1;
	int total_zero = (cc[0] == 0) ? 1:0;
	for(int i = 1; i < n; i++){
		if (cc[i] == 0) { cc[i] = cc[i-1]; total_zero++; continue; }
		if (cc[i] != 0 && cc[i-1] != 0 && cc[i] != cc[i-1]) total_k++;
	}
	if (total_k > k) { cout << -1 << endl; return 0; }
	if (total_zero == 0 && total_k != k) { cout << -1 << endl; return 0; } 
	if (total_zero == 0 && total_k == k) { cout << 0 << endl; return 0; }
	ll total_sum = 0;
	for(int i = 0; i < n; i++){
		int prev_color = i-1;
		int next_color = i+1;
		while(prev_color >= 0 && c[prev_color] == 0){
			prev_color--;
		}
		while(next_color < n && c[next_color] == 0){
			next_color++;
		}
		if (total_k == k){

		}
		else {
			
			total_k++;
		}
	}
	cout << total_sum << endl;
	return 0;
}

