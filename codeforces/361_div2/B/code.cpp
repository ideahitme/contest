#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e9+7;
const int MIN = -1e9;
const int PRIME = 1e9+7;
const ll lMAX = 1e15;
const ll lMIN = -1e15;

void dijkstra(int start, const vector<vector<pii>> &graph, vector<int> &min_dist){
	int n = graph.size();
	auto comp = [](const pii &a, const pii &b) -> bool {
		return a.second > b.second;
	};
	priority_queue<pii, vector<pii>, decltype(comp)> q(comp);
	q.push({start, 0});
	min_dist[start] = 0;
	while(!q.empty()){
		pii cur = q.top();
		q.pop();
		int ver = cur.first;
		int weight = cur.second;
		for(auto it = graph[ver].begin(); it != graph[ver].end(); it++){
			pii next = *it;
			int next_ver = next.first;
			int next_weight = next.second;
			if (min_dist[next_ver] > min_dist[ver] + next_weight){
				min_dist[next_ver] = min_dist[ver] + next_weight;
				q.push({next_ver, min_dist[next_ver]});
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 1) cout << 0 << endl;
	vector<vector<pii>> graph(n);
	for(int i = 0; i < n; i++){
		if (i < n-1) graph[i].push_back({i+1, 1});
		if (i > 0) graph[i].push_back({i-1, 1});
	}
	vector<int> min_dist(n, MAX);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		graph[i].push_back({x-1,1});
	}
	dijkstra(0, graph, min_dist);
	for(int i = 0; i < n; i++){
		cout << min_dist[i] << " ";
	}
	cout << endl;
	/* code */
	return 0;
}
