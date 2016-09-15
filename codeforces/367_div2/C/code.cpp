#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;
typedef pair<ll,ll> pll;
void dijkstra(int start, const vector<vector<pll>> &graph, vector<ll> &min_dist){
	int n = graph.size();
	auto comp = [](const pll &a, const pll &b) -> bool {
		return a.second > b.second;
	};
	priority_queue<pll, vector<pll>, decltype(comp)> q(comp);
	q.push({start, 0});
	min_dist[start] = 0;
	while(!q.empty()){
		pll cur = q.top();
		q.pop();
		int ver = cur.first;
		int weight = cur.second;
		for(auto it = graph[ver].begin(); it != graph[ver].end(); it++){
			pll next = *it;
			ll next_ver = next.first;
			ll next_weight = next.second;
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
	ll n;
	cin >> n;
	vector<ll> c(n);
	vector<string> s(n);
	for(ll i = 0; i < n; i++){
		cin >> c[i];
	}
	for(ll i = 0; i < n; i++){
		cin >> s[i];
	}
	vector<vector<pll>> graph(2*n+1);
	for(ll i = 0; i < n-1; i++){
		string cs = s[i];
		string rcs = cs;
		reverse(rcs.begin(), rcs.end());
		string ns = s[i+1];
		string rns = ns;
		reverse(rns.begin(), rns.end());
		if (cs <= ns){
			graph[2*i].push_back({2*(i+1), 0});
		}
		if (cs <= rns){
			graph[2*i].push_back({2*(i+1)+1, c[i+1]});
		}
		if (rcs <= ns){
			graph[2*i+1].push_back({2*(i+1), 0});
		}
		if (rcs <= rns){
			graph[2*i+1].push_back({2*(i+1)+1, c[i+1]});
		}
	}
	graph[2*n].push_back({0, 0});
	graph[2*n].push_back({1, c[0]});
	vector<ll> min_dist(2*n+1, 1e15);
	dijkstra(2*n, graph, min_dist);
	ll answer = min({min_dist[2*n-1], min_dist[2*n-2]});
	if (answer < 1e15) cout << answer << endl;
	else cout << -1 << endl;
	return 0;
}
