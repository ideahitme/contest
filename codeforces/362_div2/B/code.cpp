#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e9;
const ll lMAX = 1e15;
const int PRIME = 1e9+7;

int main(int argc, char const *argv[])
{
	string x;
	string res;
	cin >> x;
	int dot = -1;
	for(int i = 0; i < x.length(); i++){
		if (x[i] == '.'){
			dot = i;
			break;
		}
	}
	if (dot == -1){
		cout << x << endl;
		return 0;
	}
	if (atoi(x.substr(0,dot).c_str()) == 0){
		cout << x.substr(0,x.length()-2) << endl;
		return 0;
	}
	res += x.substr(0,dot);
	int e = -1;
	for(int i = dot+1; i < x.length(); i++){
		if (x[i] == 'e'){
			e = i;
		}
	}
	if (e == -1){
		cout << x << endl;
	}
	int b = atoi(x.substr(e+1, x.length()-e-1).c_str());
	if (b == 0){
		cout << x.substr(0, e) << endl;
		return 0;
	}
	string d = x.substr(dot+1, e-dot-1);
	if (d.length() == 1){
		int intd = atoi(d.c_str());
		if (intd == 0){
			string zeroes(b, '0');
			res += zeroes;
			cout << res << endl;
			return 0;
		} else {
			string zeroes(b-1, '0');
			res += d;
			res += zeroes;
			cout << res << endl;
		}
	}
	else {
		if (d.length() > b){
			res += d.substr(0, b);
			res += ".";
			res += d.substr(b, d.length()-b);
			cout << res << endl;
		}
		else {
			string zeroes(b-d.length(), '0');
			res += d;
			res += zeroes;
			cout << res << endl;
		}
	}
	/* code */
	return 0;
}

