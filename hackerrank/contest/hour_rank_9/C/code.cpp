#define MAX 999999999

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

inline int positive_modulo(int i, int n) {
    return (i % n + n) % n;
}

vector<int> dijkstra_set(vector<vector<pair<int, int> > > &edges, int source, int M){
	int size = edges.size();
	int imax = numeric_limits<int>::max();
	vector<int> min_dist(size, MAX);
	min_dist[source] = 0;
	set<pair<int, int> > active_vertices;
	active_vertices.insert({0, source});
	while(!active_vertices.empty()){
		int cur = active_vertices.begin()->second;
		active_vertices.erase( active_vertices.begin() );
		for(auto j = edges[cur].begin(); j != edges[cur].end(); j++){
			int weight = positive_modulo(j->second, M);
			int neighbour = j->first;
			if (min_dist[neighbour] > min_dist[cur] + weight) {
				active_vertices.erase( { min_dist[neighbour], neighbour });
				min_dist[neighbour] = min_dist[cur] + weight;
				active_vertices.insert( { min_dist[neighbour], neighbour });
			}
		}
	}
	return min_dist;
}


void solution(vector<vector<pii> > &edges, int S, int E, int M){
	vector<int> min_dist = dijkstra_set(edges, S, M);
	long long dist = min_dist[E];
	long long c_dist = dist;
	long long max = 0;
	for(int i = 0; i < M; i++){
		if (positive_modulo(dist, M) > max){
			max = positive_modulo(dist, M);
		}
		dist += c_dist;
	}
	cout << max << endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<vector<pii> > edges(n);
	for(int i = 0; i < n; i++){
		int a,b,x;
		cin >> a >> b >> x;
		// cout << a << " " << b << " " << x << endl;
		edges[a-1].push_back({b-1, x});
		edges[b-1].push_back({a-1, -x});
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int S,E;
		int M;
		cin >> S >> E >> M;
		solution(edges, S-1, E-1, M);
	}
	/* code */
	return 0;
}
