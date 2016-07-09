#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int min_dist = -1;
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if (a[i] == a[j]){
				if (min_dist == -1) min_dist = j-i;
				else if (min_dist > j-i) min_dist = j-i;
			}
		}
	}
	cout << min_dist;
	return 0;
}