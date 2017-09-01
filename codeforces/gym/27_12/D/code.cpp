#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <set>
#include <queue>
#include <cmath>
#include <assert.h>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1e9;
const ll lMAX = 1e18;
const int PRIME = 1e9+7;

ll find_gcd(ll a, ll b, ll res)
{
	if (a % b == 0) { return res * b; }
	if (b % a == 0) { return res * a; }
	if (a == b) { return res * a; }
	if (a % 2 == 0 && b % 2 == 0) { return find_gcd(a/2, b/2, res*2); }
	if (a % 2 == 0) { return find_gcd(a/2, b, res); }
	if (b % 2 == 0) { return find_gcd(a, b/2, res); }
	if (a > b) { return find_gcd(a-b, b, res); }
	if (a < b) { return find_gcd(a, b-a, res); }
	return 1;
}

int main(int argc, char const *argv[])
{
	ifstream infile("lcm.in");
	ofstream outfile("lcm.out");

	int t;
	infile >> t;
	for(int i = 0; i < t; i++){
		ll a,b;
		infile >> a >> b;
		while(find_gcd(a,b,1) != 1){
			b--;
		}
		long long res = a*b;
		outfile << res << endl;
	}
	return 0;
}