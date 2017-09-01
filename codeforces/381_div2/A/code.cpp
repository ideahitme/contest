#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	ll d = 4-(n%4);
	if (d == 4) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1e12;
	if (d == 3) {
		ans = min({3*a, a + b, c, 2*b + c, a + 2*c});
	}
	if (d == 2) {
		ans = min({2*a, b, 2*c});
	}
	if (d == 1) {
		ans = min({ans, a, 3*c, b + c});
	}
	cout << ans << endl;
	/* code */
	return 0;
}
