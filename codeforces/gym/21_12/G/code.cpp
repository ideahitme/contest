#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ifstream infile("repair.in");
	ofstream ostream("repair.out");
	int n, a, b;
	infile >> n >> a >> b;
	vector<int> f(n);
	vector<int> c(100001);
	for(int i = 0; i < n; i++){
		infile >> f[i];	
		c[f[i]]++;
	}

	sort(f.begin(), f.end());
	vector<int> x;
	for(int i = 0; i < n; i++){
		if (c[f[i]] == -1) continue;
		if (c[f[i]] > 3) {
			c[f[i]] = 3;
		}
		for(int j = 0; j < c[f[i]]; j++){
			x.push_back(f[i]);
		}
		c[f[i]] = -1;
	}
	int aa,bb,cc;
	int bt, btt;
	bool found = false;
	n = x.size();
	for(int i = 0; i < n; i++){
		if (b % x[i] == 0){
			bt = b/x[i];
			for(int j = i+1; j < n; j++){
				if (bt % x[j] == 0){
					btt = bt/x[j];
					for(int k = j+1; k < n; k++){
						if (btt % x[k] == 0){
							if (x[i]+x[j]+x[k] == a) {
								aa = x[i];
								bb = x[j];
								cc = x[k];
								found = true;
								break;
							}
						}
					}
				}
			}
		}
	}
	if (found) {
		ostream << aa << " " << bb << " " << cc << endl;
	} else {
		ostream << -1 << endl;
	}
	return 0;
}