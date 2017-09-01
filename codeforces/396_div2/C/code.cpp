#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int PRIME = 1e9+7;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> a(26, 0);
	for(int i = 0; i < 26; i++){
		cin >> a[i];
	}
	vector<ll> dp(n+1, 0);
	vector<int> partdp(n, 1e8);
	dp[n] = 1;
	partdp[n] = 0;
	int max_len = -1;
	for(int i = n-1; i >= 0; i--){
		int min_len = a[s[i]-'a'];
		for(int j = 0; i + j < n; j++){
			min_len = min({a[s[i+j]-'a'], min_len});
			if (min_len < j+1) break;
			max_len = max({max_len, j+1});
			dp[i] += dp[i+j+1];
			dp[i] %= PRIME;
			partdp[i] = min({partdp[i], partdp[i+j+1]+1});
		}
	}
	cout << dp[0] << endl;
	cout << max_len << endl;
	cout << partdp[0] << endl;
	return 0;
}
