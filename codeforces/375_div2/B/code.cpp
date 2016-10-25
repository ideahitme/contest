#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string x;
	cin >> x;
	cout << x << endl;
	bool par_open = false;
	int i_w = 0;
	for(int i = 0; i < n; i++){
		if (x[i] == '('){
			par_open = true;
			continue;
		}
		if (x[i] == ')'){
			par_open = false;
			continue;
		}
		if (x[i] == '_'){
			if (i > 0 && x[i-1] != '_') i_w++;				
			continue;
		}

	}
	return 0;
}
