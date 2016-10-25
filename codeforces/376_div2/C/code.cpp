#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath> 
#include <unordered_map>
#include <map>

using namespace std;

typedef long long ll;

class DisjointSet{
public:
	DisjointSet();
	DisjointSet(int n);
	~DisjointSet();
	int find(int i){
		if (p[i] == i) return i;
		return p[i] = find(p[i]);
	}
	void unite(int i, int j){
		i = find(i);
		j = find(j);
		if (i == j) return;
		if (rand() % 2 == 0){
			swap(i, j);
		}
		p[i] = j;
		size[j] += size[i];
		size[i] = 0;
	}
	ll calc(vector<int> &socks, int k){
		ll res = 0;
		int n = socks.size();
		vector<vector<int>> dist(n);
		for(int i = 0; i < n; i++){
			dist[find(i)].push_back(i);
		}
		for(int i = 0; i < n; i++){
			if (size[i] > 1){
				map<int, int> m;				
				for(int j = 0; j < dist[i].size(); j++){
					m[socks[dist[i][j]]]++;
				}
				int _m = -1;
				for(auto it: m){
					_m = max({it.second, _m});
				}
				res += (size[i]-_m);
			}
		}
		return res;
	}
private:
	vector<int> p;
	vector<int> size;
};

DisjointSet::DisjointSet(int n){
	for(int i = 0; i < n; i++){
		p.push_back(i);
	}
	size.resize(n, 1);
};
DisjointSet::~DisjointSet(){};


typedef long long ll;
typedef pair<int,int> pii;

const int PRIME = 1e9+7;
const int MAX = 1e9+10;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> colors(k, 0);
	vector<int> socks(n);
	for(int i = 0; i < n; i++){
		int c; cin >> c;
		socks[i] = c;
	}
	DisjointSet d(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--;b--;
		d.unite(a,b);
	}
	cout << d.calc(socks, k) << endl;
	return 0;
}