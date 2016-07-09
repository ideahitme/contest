#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define iMAX (int)1e9
#define iMIN -(int)1e9

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void dijkstra(vector<int> &min_dist, vector<vector<pii>> &graph, int from, int lim){
	int n = min_dist.size();
	auto comp = [](const pii &a, const pii &b) -> bool {
		return a.second > b.second;
	};
	priority_queue<pii, vector<pii>, decltype(comp)> q(comp);
	min_dist[from] = 0;
	q.push({from, 0});
	while(!q.empty()){
		pii p = q.top();
		q.pop();
		int cur = p.first;
		for(auto it = graph[cur].begin(); it != graph[cur].end(); it++){
			pii n = *it;
			int neigh = n.first;
			int weight = n.second;
			if (min_dist[neigh] > min_dist[cur] + weight){
				min_dist[neigh] = min_dist[cur] + weight;
				q.push({neigh, min_dist[neigh]});
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int n, e, t, m;
	cin >> n >> e >> t >> m;
	e--;
	vector<vector<pii>> graph(n); //reverse graph
	for(int i = 0; i < m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		graph[b-1].push_back({a-1, c});
	}
	vector<int> min_dist(n, iMAX);
	dijkstra(min_dist, graph, e, t);
	int total = 0;
	for(int i = 0; i < min_dist.size(); i++){
		if (min_dist[i] <= t) total++;
	}
	cout << total << endl;
	return 0;
}
