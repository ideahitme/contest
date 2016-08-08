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
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		string x;
		cin >> x;
		vector<int> count(26);
		int total = 0;
		for(int i = 0; i < x.length(); i++){
			if (count[x[i]-'a'] == 0){
				count[x[i]-'a']++;
				total++;
			}
		}
		cout << total << endl;
	}
	return 0;
}
