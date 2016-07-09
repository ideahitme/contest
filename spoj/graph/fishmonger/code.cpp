#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

ll min_so_far = 1e15;
ll ans_dist;


struct edge{
	int dist;
	int toll;
	int vertex;
	edge(int dist, int toll, int vertex): dist(dist), toll(toll), vertex(vertex) {};
};

void dijkstra(const vector<vector<int>> &dist, const vector<vector<int>> &toll, int limit){
	int n = dist.size();
	auto comp = [](const edge &a, const edge &b) -> bool {
		return a.toll > b.toll || ( a.toll == b.toll && a.dist > b.dist);
	};
	vector<int> min_dist(n, 1e9);
	priority_queue<edge, vector<edge>, decltype(comp)> q(comp);	
	vector<vector<bool>> visited(n, vector<bool>(limit+1, false));
	edge e(0,0,0);
	q.push(e);
	while(!q.empty()){
		edge cur = q.top();
		q.pop();
		int cur_ver = cur.vertex;
		int cur_toll = cur.toll;
		int cur_dist = cur.dist;
		if (visited[cur_ver][cur_dist] || min_so_far < cur_toll) continue;
		visited[cur_ver][cur_dist] = true;
		if (cur_ver == n-1){
			if (min_so_far > cur_toll || (min_so_far == cur_toll && cur_dist < ans_dist)){
				ans_dist = cur_dist;
				min_so_far = cur_toll;
			}
		}
		else{
			for(int i = 0; i < n; i++){
				if (i != cur_ver){
					edge e(cur_dist + dist[cur_ver][i], cur_toll+toll[cur_ver][i], i);
					if (cur_dist + dist[cur_ver][i] <= limit && !visited[i][cur_dist + dist[cur_ver][i]]) q.push(e);
				}
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	while(true){
		int n ,t;
		cin >> n >> t;
		if (n == 0)  break;
		vector<vector<int> > dist(n, vector<int>(n));
		vector<vector<int> > toll(n, vector<int>(n));

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> dist[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> toll[i][j];
			}
		} 
		vector<bool> visited(n, false);
		dijkstra(dist, toll, t);

		cout << min_so_far << " " << ans_dist << endl;		
		min_so_far = 1e15;
		ans_dist = 0;
	}
	return 0;
}

