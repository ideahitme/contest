#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b, int res){
	if (a % b == 0) return res * b;
	if (b % a == 0) return res * a;
	if (a == b) return res * a;
	if (a % 2 == 0 && b % 2 == 0) return gcd(a/2, b/2, res*2);
	if (a % 2 == 0) return gcd(a/2, b, res);
	if (b % 2 == 0) return gcd(a, b/2, res);
	if (a > b) return gcd(a-b, b, res);
	if (a < b) return gcd(a, b-a, res);
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a = 1234567;
	int b = 123456;
	int c = 1234;
	bool res = false;
	for(int i_a = 0; i_a < 1000; i_a++){
		if (i_a * a <= n){
			int to_reach = n - (i_a * a);
			for(int i_b = 0; i_b < 10000; i_b++){
				if (i_b * b <= to_reach){
					int final = to_reach - (i_b * b);
					if (final % c == 0){
						res = true;
					}
				}
				else break;
			}
		}
		else break;
	}
	if (res) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
