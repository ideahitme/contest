#include <algorithm>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n,q;
	int cur = 0;
	cin >> n >> q;
	vector<set<int>> e(n);
	vector<bool> mark(q, false);
	set<pair<int,int>> Q;
	int unread = 0;
	for(int i = 0; i < q; i++){
		int t,x;
		cin >> t >> x;
		if (t == 1){
			x--;
			e[x].insert(cur);
			Q.insert({cur, x});
			cur++;
			unread++;
		}
		if (t == 2){
			x--;
			unread -= e[x].size();
			for(auto it: e[x]){
				mark[it] = true;
			}
			e[x].clear();
		}
		if (t == 3){
			while(!Q.empty() && Q.begin()->first < x){
				int i = Q.begin()->first;
				int x = Q.begin()->second;
				Q.erase(Q.begin());
				if (!mark[i]){
					mark[i] = true;
					e[x].erase(e[x].begin());
					unread--;
				}
			}
		}
		cout << unread << endl;
	}
	return 0;
}
