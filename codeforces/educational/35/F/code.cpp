#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int PRIME = 1e9+7;

const int MAX = - 1 + (1<<30) + (1<<30);
const int MIN = -(1<<31);
const ll lMAX = -1LL + (1LL<<62) + (1LL<<62);
const ll lMIN = -(1LL<<63);

int bfs(vector<vector<int>> &g, int from){
    queue<int> q;
    vector<bool> visited(g.size(), false);
    q.push(from);
    int next = from;
    visited[from] = true;
    while(!q.empty()) {
        int t = q.front();
        visited[t] = true;
        next = t;
        q.pop();
        for(int i = 0; i < g[t].size(); i++) {
            if (!visited[g[t][i]]) {
                q.push(g[t][i]);
            }
        }
    }
    return next;
}

int main()
{
	ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>());
    for(int i = 0; i < n-1; i++) {
        int v, w;
        cin >> v >> w;
        v--;
        w--;
        g[v].push_back(w);
        g[w].push_back(v);
    }

    int a = bfs(g, 0);
    int b = bfs(g, a);



	return 0;
}