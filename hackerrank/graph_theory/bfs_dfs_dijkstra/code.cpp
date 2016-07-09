#define MAX 999999999

#include <limits>
#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

struct pair_compare_reverse
{
    bool operator()(pair<int, int> &a, pair<int, int> b)
    {
        return a.second < b.second || a.second == b.second && a.first < b.first;
    }
};

vector<int> dijkstra_set(vector<vector<pair<int, int> > > &edges, int source){
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
			int weight = j->second;
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

vector<int> dijkstra_pqueue(vector<vector<pair<int, int> > > &edges, int source){
	int size = edges.size();
	int imax = numeric_limits<int>::max();
	vector<int> min_dist(size, MAX);
	min_dist[source] = 0;
	auto comp = [] (pair<int, int> *a, pair<int, int> *b) -> bool { return a->first < b->first; };
	priority_queue<pair<int, int>, vector<pair<int, int> >, pair_compare_reverse> active_vertices;
	active_vertices.push({0, source});
	while(!active_vertices.empty()){
		int cur = active_vertices.top().second;
		active_vertices.pop();
		for(auto j = edges[cur].begin(); j != edges[cur].end(); j++){
			int weight = j->second;
			int neighbour = j->first;
			if (min_dist[neighbour] > min_dist[cur] + weight) {
				min_dist[neighbour] = min_dist[cur] + weight;
				active_vertices.push({ min_dist[neighbour], neighbour });
			}
		}		
	}
	return min_dist;
}

int main(int argc, char const *argv[])
{
	int num_cases;
	cin >> num_cases;
	for(int i = 0; i < num_cases; i++){
		int num_vertices, num_edges;
		cin >> num_vertices >> num_edges;
		vector<vector<pair<int, int> > > edges(num_vertices);
		for(int j = 0; j < num_edges; j++){
			int x,y,r;
			cin >> x >> y >> r;
			edges[x-1].push_back({y-1, r});
			edges[y-1].push_back({x-1, r});
		}
		int start_node;
		cin >> start_node;
		vector<int> min_dist = dijkstra_pqueue(edges, start_node-1);
		int j = 0;
		for(auto i = min_dist.begin(); i != min_dist.end(); i++){
			j++;
			if (j != start_node && *i < MAX){
				cout << *i << " ";			
			}
			else if (j != start_node){
				cout << (-1) << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
