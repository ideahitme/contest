#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, q, k;
	cin >> n >> q >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}	
	vector<pii> ranges(q);
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		sort(a.begin()+l, a.begin()+r+1);
	}
	while(true){
		int cur_start = ranges[i].first;
		int cur_end = ranges[i].second;
		i++;
		if (i >= q) break;
		while(true){
			int next_start = ranges[i].first;
			if (cur_end >= next_start){
				cur_end = ranges[i].second;
				i++;
			}
			else {
				break;
			}
		}
		if (i >= q){
			break;
		}
	}
	return 0;
}
