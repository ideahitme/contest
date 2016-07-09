#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dfs(int start, const vector<vector<int>> &graph, vector<bool> &visited, int &ans){
	int num_vert = 0;
	visited[start] = true;
	for(int i = 0; i < graph[start].size(); i++){
		int j = graph[start][i];
		if (!visited[j]){
			int num_vert_sub = dfs(j, graph, visited, ans);
			if (num_vert_sub % 2 == 0) ans++;
			else {
				num_vert += num_vert_sub;
			}
		}
	}
	return (num_vert + 1);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	vector<bool> visited(n, false);
	vector<vector<int>> graph(n);
	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		graph[x-1].push_back(y-1);
		graph[y-1].push_back(x-1);
	}
	dfs(0, graph, visited, ans);
	cout << ans << endl;
	return 0;
}
