#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1e9+10;
const int PRIME = 1e9+7;

void print(vector<pii> &x){
	for(auto it: x){
		cout << it.first << " " << it.second << endl;
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> a(n, 0);
	vector<pii> x(m);
	for(int i = 0; i < m; i++) { 
		x[i] = {0, i+1};
	}
	int buffer = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > m) buffer++;
		else x[a[i]-1].first++;
	}
	int target = n/m;
	int changes = 0;
	for(int i = 1; i <= m; i++){
	 	int j;
	 	j = 0;
	 	while(buffer > 0 && x[i-1].first < target && j < n){
	 		if (a[j] > m) {
	 			buffer--;
	 			changes++;
	 			a[j] = i;
	 			x[i-1].first++;
	 		}
 			j++;
	 	}
	 	j = 0;
	 	while(buffer == 0 && x[i-1].first < target && j < n){
	 		if (a[j] <= m && x[a[j]-1].first > target) {
	 			changes++;
	 			x[i-1].first++;
	 			x[a[j]-1].first--;
	 			a[j] = i;
	 		}
 			j++;
	 	}
	}
	cout << target << " " << changes << endl;
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
