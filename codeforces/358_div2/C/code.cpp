#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <queue>

using namespace std;

vector<long long> dist_to_root(vector<vector<pair<int,int>>> &edges, int n){
	vector<long long> dist(n, 0);
	queue<int> s;
	set<int> visited;
	visited.insert(0);
	s.push(0);
	while(!s.empty()){
		int cur = s.front();
		s.pop();
		for(int i = 0; i < edges[cur].size(); i++){
			pair<int, int> p = edges[cur][i];
			
			s.push(p.first);
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[i] = x;
	}
	vector<vector<pair<int,int>>> edges(n);
	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		p--;
		int w;
		edges[i].push_back({p, w});
	}
	vector<long long> dist = dist_to_root(edges, n);
	return 0;
}
