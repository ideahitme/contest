#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	ll total = m;
	int sad = 0;
	for(int i = 0; i < n; i++){
		char x;
		int val;
		cin >> x >> val;
		if (x == '+'){
			total += val;
		}
		else {
			if (total >= val) total-= val;
			else sad++;
		}
	}
	cout << total << " " << sad << endl;
	return 0;
}
