#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> files(m);
	for(int i = 0; i < m; i++){
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			int t;
			cin >> t;
			t--;
			files[i].push_back(t);
		}
	}
	vector<int> next(n, -1);
	vector<pii> ops;
	int total_size = 0;
	for(int i = 0; i < m; i++){
		int si = files[i].size();
		for(int j = 0; j < si; j++){
			int t = files[i][j];
			next[t] = total_size + j;
		}
		total_size += si;
	}
	int empty;
	for(int i = n-1; i > -1; i--){
		if (next[i] == -1) { empty = i; break; }
	}
	bool stop = false;
	while(!stop) {
		stop = true;
		for(int i = 0; i < n; i++){
			if (next[i] == -1 || next[i] == i) continue;
			int to = next[i];
			if (to == empty){
				ops.push_back({i, empty});
				next[to] = to;
				stop = false;
			}
			else {
				next[empty] = next[to];
				ops.push_back({to, empty});
				next[to] = to;
				ops.push_back({i, to});
				stop = false;
			}
			empty = i;
			next[empty] = -1;
	 	}
	}
 	cout << ops.size() << endl;
 	for(int i = 0; i < ops.size(); i++){
 		cout << ops[i].first + 1 << " " << ops[i].second + 1 << endl;
 	}
	return 0;
}
