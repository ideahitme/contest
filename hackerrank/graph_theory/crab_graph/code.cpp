#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct edge{
	int f = 0;
	int c = 0;
	edge(int f, int c):f(f),c(c){}
};

bool find_update_path(vector<vector<edge>> &graph){
	int n = graph.size();
	bool path_found = false;
	/** bfs */
	queue<int> q;
	vector<int> prev(n, -1);
	vector<bool> visited(n, false);
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		int cur = q.front();
		if (cur == n-1){
			path_found = true;
			while(prev[cur] != -1){
				int par = prev[cur];
				graph[par][cur].f += 1;
				graph[cur][par].f -= 1;
				cur = par;
			}
			break;
		}
		q.pop();
		for(int i = 0; i < n; i++){
			if (i != cur && graph[cur][i].f < graph[cur][i].c && !visited[i]){
				prev[i] = cur;
				visited[i] = true;
				q.push(i);
			}
		}
	}
	return path_found;
}

int main(int argc, char const *argv[])
{	
	ios::sync_with_stdio(false);
	int c;
	cin >> c;
	for(int _ = 0; _ < c; _++){
		int n,t,m;
		cin >> n >> t >> m;
		vector<vector<edge>> graph(2*n+2, vector<edge>(2*n+2, edge(0,0)));
		vector<int> degree(n, 0);
		for(int i = 0; i < m; i++){
			int u,v;
			cin >> u >> v;
			graph[u][n+v].c = 1;
			graph[n+v][u].c = 1;
			graph[n+v][u].f = 1;
			graph[v][n+u].c = 1;
			graph[n+u][v].c = 1;
			graph[n+u][v].f = 1;
			degree[u-1]++;
			degree[v-1]++;
 		}
		for(int i = 1; i < n+1; i++){
			graph[0][i].c = min({degree[i-1],t});
			graph[i][0].c = min({degree[i-1],t});
			graph[i][0].f = min({degree[i-1],t});
		}
		for(int i = n+1; i < 2*n+1; i++){
			graph[i][2*n+1].c = 1;
			graph[2*n+1][i].c = 1;
			graph[2*n+1][i].f = 1;
		}
		while(find_update_path(graph)){

		}
		vector<bool> is_head(n, false);
		vector<bool> is_count(n, false);
		for(int i = 1; i < n+1; i++){
			if (graph[0][i].f > 0){
				is_head[i-1] = true;
				is_count[i-1] = true;
			}
		}
		for(int i = 1; i < n+1; i++){
			if (is_head[i-1]){
				for(int j = n+1; j < 2*n+1; j++){
					if (graph[i][j].f > 0){
						is_count[j-n-1] = true;
					}
				}
			}	
		}
		int total = 0;
		for(int i = 0; i < n; i++){
			if (is_count[i]) total++;
		}
		cout << total << endl;
	}
	return 0;
}
