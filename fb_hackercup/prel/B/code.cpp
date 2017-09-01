#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <fstream>
#include <ostream>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	ifstream infile("input");
	ofstream outfile("output.out");

	int t;
	infile >> t;
	for(int k = 0; k < t; k++){
		int n;
		infile >> n;
		vector<int> x(101, 0);
		for(int j = 0; j < n; j++){
			int w;
			infile >> w;
			x[w]++;
		}
		int ans = 0;
		for(int i = 50; i < 101; i++){
			ans += x[i];
			x[i] = 0;
		}
		int i = 49;
		while(i >= 1){
			if (x[i] == 0){ 
				i--;
				continue;
			}
			x[i]--;
			int required = ceil(50.0/(i))-1;
			int j = 1;
			while(required > 0){
				if (j > i) break;
				if (x[j] == 0){
					j++;
					continue;
				}
				x[j]--;
				required--;
			}
			if (required > 0) break;
			ans++;
		}
		outfile << "Case #" << (k+1) << ": " << ans << endl;
	}
	return 0;
}