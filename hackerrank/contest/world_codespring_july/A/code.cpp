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

int main(int argc, char const *argv[])
{
	string x;
	cin >> x;
	int total = 1;
	for(int i = 0; i < x.length(); i++){
		if (x[i] >= 'A' && x[i] <= 'Z') total++;
	}
	cout << total;
	return 0;
}
