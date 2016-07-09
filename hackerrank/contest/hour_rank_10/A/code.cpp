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
	int n, k;
	cin >> n >> k;
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	int start = 0;
	int E = 100;
	while(true){
		start = (start + k) % n;
		E--;
		if (c[start] == 1) E-=2;
		if (start == 0) break;	
	}
	cout << E << endl;
	return 0;
}
