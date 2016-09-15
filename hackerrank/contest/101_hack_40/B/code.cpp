#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	cin >> m;
	vector<int> x(m);
	for(int i = 0; i < m; i++){
		cin >> x[i];
	}
	vector<int> fin(n+1, 0);
	sort(x.begin(), x.end());
	int cur = m;
	for(int i = n; i >= 1; i--){
		if (cur == m){
			fin[i] = h[i-1];
		}
		else fin[i] = min({h[i-1], x[cur]-i});
		if (cur > 0 && x[cur-1] == i){
			cur--;
		}
		while(cur > 0 && x[cur] == x[cur-1]) cur--;
	}
	ll answer = 0;
	for(auto it: fin){
		answer += it;
	}
	cout << answer << endl;
	return 0;
}
