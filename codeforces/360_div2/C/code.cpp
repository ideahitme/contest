#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e9+7;
const int MIN = -1e9;
const int PRIME = 1e9+7;
const ll lMAX = 1e15;
const ll lMIN = -1e15;

bool is_bipartite(int start, const vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &color){
	bool is_bipartite = true;
	queue<int> to_visit;
	to_visit.push(start);
	visited[start] = true;
	color[start] = true;
	while(!to_visit.empty()){
		int cur = to_visit.front();
		to_visit.pop();
		for(auto it = graph[cur].begin(); it != graph[cur].end(); it++){
			int neigh = *it;
			if (!visited[neigh]){
				to_visit.push(neigh);
				visited[neigh] = true;
				if (color[cur]) color[neigh] = false;
				else color[neigh] = true;
			}
			else if (color[neigh] == color[cur]) {
				is_bipartite = false;
			}
		}
		if (!is_bipartite) break;
	}
	return is_bipartite;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		graph[x-1].push_back(y-1);
		graph[y-1].push_back(x-1);
	}
	int start = 0;
	vector<bool> visited(graph.size(), false);
	vector<bool> color(graph.size(), false);
	vector<int> A;
	vector<int> B;
	for(int i = 0; i < graph.size(); i++) { 
		if (!visited[i] && graph[i].size() > 0) { 
			// cout << (i+1) << endl;
			// for(int i = 0; i < graph.size(); i++) {
			// 	cout << (i+1) << " visited: " << visited[i] << endl;
			// }			
			if (!is_bipartite(i, graph, visited, color)) {
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	// for(int i = 0; i < graph.size(); i++) {
	// 	cout << (i+1) << " vertex color: " << color[i] << endl;
	// }
	for(int i = 0; i < graph.size(); i++) {
		if (color[i]) { 
			A.push_back(i+1);
		} else { 
			B.push_back(i+1);
		}
	}
	cout << A.size() << endl;
	for(int i = 0; i < A.size();i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	cout << B.size() << endl;
	for(int i = 0; i < B.size();i++) {
		cout << B[i] << " ";
	}
	cout << endl;
	/* code */
	return 0;
}

