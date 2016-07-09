#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_ancestor(int i, int j, vector<int> &p){ //if i is ancestor of j
	if (i == j) return true;
	while(p[j] != i){
		if (p[j] = j) break;
		else j = p[j];
	}
	return p[j] == i;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	vector<int> s(n);
	set<int> res;
	for(int i = 0; i < n; i++){
		p[i] = i;
		s[i] = i;
	}
	for(int i = 0; i < m; i++){
		int q,s;
		cin >> q >> s;
		p[s-1] = q-1;	
		s[q-1] = s-1;
	}
	bool pos = true;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (is_ancestor(i, x-1, p)){
			set.insert(x-1);
		}
		else{
			pos = false;
			break;
		}
		p[i] = i;
	}
	if (!pos){
		cout << -1 << endl;
	}
	else {
		cout << res.size();
		for(int i = 0; i < res.size(); i++){
			cout << res[i] << endl;
		}
	}
	// int x = 1;
	// vector<int*> t;
	// for(int i = 0; i < 3; i++){
	// 	t.push_back(&x);
	// }
	// cout << *t[0] << endl;
	// x = 2;
	// cout << *t[0] << endl;
	return 0;
}
