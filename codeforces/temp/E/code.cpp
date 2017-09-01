#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> x;

void exec(vector<int> &vals) {
	int kmax = n/8;
	for(int ans = kmax; ans >= 1; ans--){
		
	}
}

void perm(int cur, vector<int> &vals){
	if (cur == 8) {
		exec(vals);
	}
	else {
		vector<bool> taken(8, false);
		for(int j = 0; j < cur; j++){
			int x = vals[j];
			taken[x] = true;
		}
		for(int i = 0; i < 8; i++) {
			if (!taken[i]) {
				vals[cur] = i;
				perm(cur + 1, vals);
			}
		}
	}
}




int main(int argc, char const *argv[])
{
	cin >> n;
	x.resize(n);
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		x[i] = t-1;
	}
	vector<int> vals(8);
	perm(0, vals);
	return 0;
}
