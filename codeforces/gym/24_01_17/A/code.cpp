#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void largest_prime(int k, int i, vector<pii> &primes) {
	while(i * i <= k){
		if (k % i == 0){
			primes.push_back({i, 0});
			while(k % i == 0) {
				k /= i;
				primes[primes.size()-1].second++;
			}
			return largest_prime(k, (i+1), primes);
		}
		i++;
	}
	primes.push_back({k, 1});
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		int n, k;
		cin >> n >> k;
		vector<pii> primes;
		largest_prime(k, 2, primes);
		int ans = 1e8;
		for(int i = 0; i < primes.size(); i++){
			int factor = primes[i].first;
			if (factor == 1) continue;
			int num = 0;
			while(n >= factor){
				num += n/factor;
				factor *= primes[i].first;
			}
			num /= primes[i].second;
			ans = min({num, ans});
		}
		if (ans == 1e8){
			cout << "Case " << (i+1) << ": " << 0 << endl;
		}
		else cout << "Case " << (i+1) << ": " << ans << endl;
	}
	return 0;
}

