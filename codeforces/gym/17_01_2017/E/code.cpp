#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <fstream>
#include <ostream>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);

	ifstream infile("digits.in");
	ofstream outfile("digits.out");

	int n, k;
	ll answer = 0;
	infile >> n >> k;
	vector<string> x(n);
	for(int i = 0; i < n; i++){
		infile >> x[i];
	}

	vector<double> pows = {1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};

	vector<vector<int>> m(11, vector<int>(10, 0));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < x[i].length(); j++){
			m[x[i].length()-j-1][x[i][j]-'0']++;
		}
	}

	bool found = true;
	while(found && k > 0) {
		found = false;
		for(int i = 10; i >= 0; i--){
			for(int j = 0; j <= 8; j++){
				if (m[i][j] > 0) {
					// cout << i << " " << j << endl;
					found = true;
					// ll tx = ll(pow(10.0, double(i)));
					ll tx = ll(pows[i]);
					ll ty = tx * ll(9-j);
					if (k > m[i][j]) {
						answer += ll(m[i][j])*ty;
						k -= m[i][j];
						m[i][j] = 0;
					} else {
						answer += ll(k)*ty;
						m[i][j] -= k;
						k = 0;
					}
				}
			}
		}
	}
	outfile << answer << endl;
	return 0;
}

