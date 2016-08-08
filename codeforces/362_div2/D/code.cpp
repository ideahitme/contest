#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <assert.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e9;
const ll lMAX = 1e15;
const int PRIME = 1e9+7;

int c = 0;

struct pr{
	double prob;
	double time;
	pr(double prob, double time): prob(prob), time(time) {}
};

void bfs(int start, const vector<vector<int>> &edges, vector<int> &pre, vector<int> &post, vector<double> &res, vector<vector<pr>> &probs, vector<int> parents){
	ll answer = -1;
	queue<int> to_visit;
	to_visit.push(start);
	while(!to_visit.empty()){
		int cur = to_visit.front();
		to_visit.pop();
		if (cur != 0){ //not the root
			int its_parent = parents[cur];
			double this_prob = 1.0/static_cast<double>(edges[its_parent].size());
		}
		double expt = 0.0;
		for(int i = 0; i < probs[cur].size(); i++){
			expt += probs[cur][i].prob*probs[cur][i].time;
		}
		res[cur] = expt;
		for(auto it = edges[cur].begin(); it != edges[cur].end(); it++){
			int neigh = *it;
			to_visit.push(neigh);
		}
	}
}


void explore(
		int cur,
		const vector<vector<int>> &edges,
		vector<int> &pre,
		vector<int> &post
	){	
	pre[cur] = c;
	for(auto it = edges[cur].begin(); it != edges[cur].end(); it++){
		c++;
		if (*it != cur) explore(*it, edges, pre, post);
	}
	post[cur] = c;
}




int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;
	vector<vector<int>> edges(n);
	vector<int> parents(n);
	for(int i = 1; i <= n-1; i++){
		int x;
		cin >> x;
		x--;
		edges[x].push_back(i);
		parents[i] = x;
	}
	vector<vector<pr>> probs(n, vector<pr>());
	probs[0].push_back(pr(1.0, 1));
	vector<int> pre(n);
	vector<int> post(n);
	vector<double> res(n);
	explore(0, edges, pre, post);
	bfs(0, edges, pre, post, res, probs, parents);
	for(int i = 0; i < n; i++){
		cout << setprecision(12) << res[i] << " ";
	}
	cout << endl;
	/* code */
	return 0;
}

