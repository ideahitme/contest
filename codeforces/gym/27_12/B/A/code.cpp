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

typedef pair<ll, ll> pll;

bool bfs(int start, vector<bool> &unhealthy, const vector<vector<int>> &graph, vector<int> &color){
	queue<int> to_visit;
	vector<int> visited(graph.size(), 0);
	to_visit.push(start);
	visited[start] = 1;
	bool repeat = false;
	while(!to_visit.empty()){
		int cur = to_visit.front();
		to_visit.pop();
		for(auto it = graph[cur].begin(); it != graph[cur].end(); it++){
			int neigh = *it;
			if (visited[neigh] == 0){
				to_visit.push(neigh);
				visited[neigh] = 1;
			}
		}
	}
	return repeat;
}


int main(int argc, char const *argv[])
{
	ifstream infile("bipartite.in");
	ofstream outfile("bipartite.out");

	int n, m;
	infile >> n >> m;

	vector<vector<int>> graph(n);
	vector<bool> unhealthy(n, false);
	vector<int> color(n, -1);
	for(int i = 0; i < m; i++){
		int u, v;
		infile >> u >> v;
		u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	while(bfs(0, unhealthy, graph, color)){

	}

	return 0;
}