#include <algorithm>
#include <vector>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e9+7;
const ll lMAX = static_cast<ll>(MAX);
const double dMAX = static_cast<double>(MAX);

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int l,a,n,d;
		ll total = 0;
		cin >> l >> a >> n >> d;
		int to_purchase = l/n;
		for(int j = a; j > 0; j--){
			if (l == 0) break;
			l -= to_purchase;
			total += j*to_purchase;
		}
		if (l == 0) cout << total << endl;
		else cout << "SAD" << endl;
	}
	return 0;
}
