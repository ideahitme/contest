#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ifstream infile("lucky.in");
	ofstream ostream("lucky.out");
	int n, m;
	infile >> n >> m;
	int _min = n-m;
	int _max = n;	

	int ans = 0;
	if (_min == 0) {
		ans++;
	}
	for(int i = 1; i < 10; i++) {
		ll t = i;
		while(t <= _max) {
			if (t >= _min) ans++;
			t = 10*t+i;
		}
	}
	ostream << ans << endl;
	return 0;
}