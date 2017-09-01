#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e9+7;
const int MIN = -1e9;
const int PRIME = 1e9+7;
const ll lMAX = 1e15;
const ll lMIN = -1e15;

string answer(string &n) { 
	int length = n.size()*2;
	string answer(length, '!');
	for(int i = 0; i < n.size(); i++) { 
		answer[i] = n[i];
		answer[length-i-1] = answer[i];
	}
	return answer;
}

int main(int argc, char const *argv[])
{
	string n;
	cin >> n;
	cout << answer(n) << endl;

	// string s1 = "1";
	// cout << answer(s1) << endl;
	// string s10 = "10";
	// cout << answer(s10) << endl;
	// string s100 = "100";
	// cout << answer(s100) << endl;
	// string s1000 = "1000";
	// cout << answer(s1000) << endl;

	return 0;
}

