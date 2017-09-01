#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <limits>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


#define EPSILON 1e-12

typedef pair<double, double> pdd;

struct cstmcmp
{
    bool operator()(pair<double, double> &a, pair<double, double> &b)
    {
    	double _a = a.first/a.second;
    	double _b = b.first/b.second;
        return _a < _b;
    }
};


class DisjointSet{
public:
	DisjointSet();
	DisjointSet(vector<int> &w, vector<int> &b, int n);
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
		weight[j] += weight[i];
		weight[i] = 0;
		beauty[j] += beauty[i];
		beauty[i] = 0;
	}
	vector<int> p;
	vector<int> weight;
	vector<int> beauty;
};

DisjointSet::DisjointSet(vector<int> &w, vector<int> &b, int n){
	for(int i = 0; i < n; i++){
		p.push_back(i);
		weight.push_back(w[i]);
		beauty.push_back(b[i]);
	}
};

DisjointSet::~DisjointSet(){};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);

	int n, m, total;
	cin >> n >> m >> total;
	vector<int> w(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin >> w[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	DisjointSet dj(w, b, n);
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		dj.unite(a,b);
	}
	vector<pii> vals;
	vector<bool> vis(n);
	int N = 0;
	priority_queue<pdd, vector<pdd>, cstmcmp> items;
	for(int i = 0; i < n; i++){
		int j = dj.find(i);
		if (!vis[j]) {
			// cout << dj.beauty[j] <<  " " << dj.weight[j] << endl;
 			items.push({static_cast<double>(dj.beauty[j]), static_cast<double>(dj.weight[j])});
			vis[j] = true;
			N++;
		}
		if (j != i || dj.beauty[j] != b[i]) {
 			items.push({static_cast<double>(b[i]), static_cast<double>(w[i])});
		}
	}
	double answer = 0;
	double cap = static_cast<double>(total);
	for(int i = 0; i < N; i++){
		if (cap <= EPSILON){
			break;
		}
		pdd cur = items.top();
		items.pop();
		double to_add = min(cur.second, cap);
  		answer += to_add*(cur.first/cur.second);
		cap -= to_add;
		cout << answer << " " << cap << " " << cur.first << " " << cur.second << endl;
	}
	// for(int i = 0; i < vals.size(); i++){
	// 	cout << vals[i].first << " " << vals[i].second << endl;
	// }
	cout << answer << endl;
	return 0;
}
