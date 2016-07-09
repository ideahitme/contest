#include <cmath>
#include <set>
#include <limits>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> dijkstra(vector<vector<int> > &edges, vector<vector<int> > &neighbours, int source){
	int size = edges.size();
	int imax = numeric_limits<int>::max();
	vector<int> min_dist(size, imax);
	min_dist[source] = 0;
	set<pair<int, int> > active_vertices;
	active_vertices.insert({0, source});
	while(!active_vertices.empty()){
		int where = active_vertices.begin()->second;
		active_vertices.erase( active_vertices.begin() );
		for(int j = 0; j < neighbours[where].size(); j++) {
			int neighbour = neighbours[where][j];
			if (min_dist[neighbour] > min_dist[where] + edges[where][neighbour]){
				active_vertices.erase( { min_dist[neighbour], neighbour });
				min_dist[neighbour] = min_dist[where] + edges[where][neighbour];
				active_vertices.insert( { min_dist[neighbour], neighbour });
			}
		}
	}
	return min_dist;
}

int main(int argc, char const *argv[])
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int> > edges(N, vector<int>(N, -1));
	vector<vector<int> > neighbours(N);
	vector<int> distr(N);
	for(int i = 0; i < N; i++){
		int ti;
		int result = 0;
		cin >> ti;
		for(int j = 0; j < ti; j++){
			int fish_type;
			cin >> fish_type;
			int fish_map = int(pow(2.0, fish_type-1));
			result = result | fish_map;
		}
		distr[i] = result;
	}
	for(int i = 0; i < M; i++){
		int X, Y, Z;
		cin >> X >> Y >> Z;
		edges[X-1][Y-1] = Z;
		neighbours[X-1].push_back(Y-1);
		edges[Y-1][X-1] = Z;
		neighbours[Y-1].push_back(X-1);
	}
	/* code */
	vector<int> min_dist = dijkstra(edges, neighbours, N-1);
	for(int i = 0; i < min_dist.size(); i++){
		cout << "distr of " << i << " is " << distr[i] << endl;
		cout << "dist between N-1 and " << i << " is " << min_dist[i] << endl;
	}
	int arr_l = int(pow(2, K));
	vector<long long> min_trav(arr_l, 0);
	return 0;
}