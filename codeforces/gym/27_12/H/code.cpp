#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <set>
#include <queue>
#include <cmath>
#include <assert.h>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1e9;
const ll lMAX = 1e18;
const int PRIME = 1e9+7;




int main(int argc, char const *argv[])
{
	ifstream infile("streets.in");
	ofstream outfile("streets.out");

	int n, m, k;
	infile >> n >> m >> k;

	vector<vector<pii>> graph(2*1e5+2);
	for(int i = 0; i <= 1e5; i++){
		if (i > 0) graph[i].push_back({i-1, 0});
		if (i < 1e5) graph[i].push_back({i+1, 0});
	}
	for(int i = 1e5+1; i <= 2*1e5+1; i++){
		if (i > 1e5+1) graph[i].push_back({i-1, 0});
		if (i < 2e5+1) graph[i].push_back({i+1, 0});
	}
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		graph[x].push_back({x+1, 1});
	}
	return 0;
}