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

typedef pair<int, int> pii;

struct pair_compare_reverse
{
    bool operator()(pair<int, int> &a, pair<int, int> b)
    {
        return a.second < b.second || a.second == b.second && a.first < b.first;
    }
};


int dijkstra_set(vector<vector<int> > &chests, vector<vector<pii> > &edges, int source_row, int source_col, int rows, int columns, int p){
	int answer_row, answer_col;
	int coff = 1000;
	vector<vector<int> > min_dist(rows+1, vector<int>(columns+1, MAX));
	min_dist[source_row][source_col] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, pair_compare_reverse> active_vertices;
	active_vertices.push({0, source_row*coff+source_col});
	while(!active_vertices.empty()){
		int cur_row = (active_vertices.top().second)/coff;
		int cur_col = (active_vertices.top().second)%coff;
		int cur_chest = chests[cur_row][cur_col];
		active_vertices.pop();
		if (cur_chest == p) {
			answer_col = cur_col;
			answer_row = cur_row;
			continue;
		}
		for(auto j = edges[cur_chest+1].begin(); j != edges[cur_chest+1].end(); j++){
			int weight;
			if (cur_row == rows){
				weight = j->first + j->second;
			}
			else{
				weight = abs(j->first-cur_row) + abs(j->second-cur_col);
			}
			if (min_dist[j->first][j->second] > min_dist[cur_row][cur_col] + weight) {
				min_dist[j->first][j->second] = min_dist[cur_row][cur_col] + weight;
				active_vertices.push( {min_dist[j->first][j->second], j->first*coff + j->second });
			}
		}
	}
	return min_dist[answer_row][answer_col];
}


int main(int argc, char const *argv[])
{
	int n, m, p;
	cin >> n >> m >> p;
	vector<vector<int> > chests(n+1, vector<int>(m+1));
	vector<vector<pii> > edges(p+1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int x;
			cin >> x;
			edges[x].push_back({i, j});
			chests[i][j] = x;
		}
	}
	chests[n][m] = 0;
	int min = dijkstra_set(chests, edges, n, m, n, m, p);
	cout << min << endl;
	return 0;
}
