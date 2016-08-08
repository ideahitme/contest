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

const ll PRIME = 1e9+7;

ll num_occ(vector<vector<int>> &calc, int i, int l, int r){
	return calc[i][r]-calc[i][l-1];
}

#define MAX 1000000007
#define FACT_MAX 1000000

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

// To generate factorials of numbers up to FACT_MAX.
// This function should be called once in main() 
void genFact(){
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < FACT_MAX; i++){
		fact[i] = mul(fact[i-1], i);
		invfact[i] = modInverse(fact[i]);
	}
}

int C(int n, int k){
	return n < k ? 0 : mul(fact[n], mul(invfact[k], invfact[n-k]));
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	ll answer = 0;
	string x;
	cin >> x;
	vector<vector<int>> calc(26, vector<int>(x.length(), 0));
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < x.length(); j++){
			if (j == 0 && x[j]-'a' == i) calc[i][j] = 1;
			if (j > 0 && x[j]-'a' == i) calc[i][j] = calc[i][j-1]+1;
			if (j > 0 && x[j]-'a' != i) calc[i][j] = calc[i][j-1];
		}
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			if (i == j) continue;
			
		}
	}
	total = (total + PRIME) % PRIME;
	genFact();
	for(int i = 0; i < 26; i++){
		ll total = calc[i][x.length()-1];
		if (total >= 4){
			answer += C(total, 4);
			answer %= PRIME;
		}
	}
	cout << (total+answer) << endl;
	return 0;
}
