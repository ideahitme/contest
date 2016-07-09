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
	int n, k;
	cin >> n >> k;
	if (k >= n){
		for(int i = 0; i < n; i++){
			cout << (n-i) << " ";
		}		
		cout << endl;
	}
	else {
		vector<int> a(n);
		vector<int> p(n+1);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			p[a[i]] = i;
		}
		for(int i = 0; i < n; i++){
			if (k == 0){
				cout << a[i] << " ";
			}
			else {
				if (a[i] != n-i){
					p[a[i]] = p[n-i];
					swap(a[i], a[p[n-i]]);
					k--;
				}
				cout << n-i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
