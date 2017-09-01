#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int PRIME = 1e9+7;

int dfs(vector<vector<int>> &graph,vector<vector<int>> &ans,int root, vector<bool> &visited, int n) {
	for(int i = 0; i < graph[root].size(); i++){
		if (!visited[graph[root][i]]){
			visited[graph[root][i]] = true;
			ans[root].push_back(graph[root][i]);
			dfs(graph, ans, graph[root][i], visited, n);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> towns(n);
	for(int i = 0; i < n; i++){
		cin >> towns[i];
	}
	vector<vector<int>> graph(n);
	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int root = 0;
	vector<bool> visited(n, false);
	vector<vector<int>> dgraph(n);

	dfs(graph, dgraph, root, visited, n);


	return 0;
}
