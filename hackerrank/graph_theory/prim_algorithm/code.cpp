#include <vector>
#include <set>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

vector<pii> prim(vector<vector<pii> > &edges, int source){
	int size = edges.size();
	vector<pii> result(size);
	return result;
}

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	vector<vector<pii> > edges(N);
	for(int i = 0; i < M; i++){
		int from, dest, weight;
		cin >> from >> dest >> weight;
		edges[from-1].push_back({dest-1, weight});
	}
	int start_node;
	cin >> start_node;
	vector<pii> result = prim(edges, start_node);
	return 0;
}
