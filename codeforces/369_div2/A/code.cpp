#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

const int MAX = 1e9+7;
const int PRIME = 1e9+9;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	bool found = false;
	vector<string> x;
	for(int i = 0; i < n; i++){
		string line;
		cin >> line;
		if (!found && line[0] == 'O' && line[1] == 'O'){
			found = true;
			line[0] = '+';
			line[1] = '+';
		}
		if (!found && line[3] == 'O' && line[4] == 'O'){
			found = true;
			line[3] = '+';
			line[4] = '+';
		}
		x.push_back(line);
	}
	if (found) cout << "YES" << endl;
	else cout << "NO" << endl;
	if (found) for(auto it: x){
		cout << it << endl;
	}
	return 0;
}

