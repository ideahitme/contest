#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int PRIME = 1e9+7;
const int MAX = 1e9+10;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	ll sum = 0;
	vector<ll> pfx;
	pfx.push_back(0);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++){
		pfx.push_back(pfx[pfx.size()-1] + a[i]);
	}
	ll cont = a[0];
	for(int i = 1; i < n; i++){
		cont += (a[i]-(a[i] % a[0]));
	}
	int j = 1;
	while(sum-pfx[j] >= cont){
		ll ncont = a[j];
		for(int i = j+1; i < n; i++){
			ncont += (a[i]-(a[i] % a[j]));
		}
		if (ncont > cont) cont = ncont;
		j++;
	}	
	cout << cont << endl;
	return 0;
}