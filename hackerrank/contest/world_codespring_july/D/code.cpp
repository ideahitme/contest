#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define MAX 1000000007
#define FACT_MAX 500000

int add(int a, int b){
	return (a + b) % MAX;
}

int mul(int a, int b){
	return ((long long)a * b) % MAX;
}

int powMod(int a, int b){
	int res = 1;
	for (; b; b >>= 1){
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
	}
	return res;
}

int modInverse(int a){
	return powMod(a, MAX - 2);
}

int fact[FACT_MAX], invfact[FACT_MAX];

int C(int n, int k){
	return n < k ? 0 : mul(fact[n], mul(invfact[k], invfact[n-k]));
}
// To generate factorials of numbers up to FACT_MAX.
// This function should be called once in main() 
void genFact(){
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < FACT_MAX; i++){
		fact[i] = mul(fact[i-1], i);
		invfact[i] = modInverse(fact[i]);
	}
}

int main(int argc, char const *argv[])
{
	genFact();
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int m, n;
		cin >> m >> n;
		vector<ll> dp(m+1, 0);
		vector<ll> h(m+1,0);
		dp[n] = 1;
		h[n] = 2;
		for(int i = n+1; i < m+1; i++){
			dp[i] += (n)*dp[i-1];
			h[i] = (n-1)*h[i-1];
			dp[i] += h[i];
			dp[i] = dp[i] % MAX;
		}
		cout << dp[m] << endl;
	}
	return 0;
}
