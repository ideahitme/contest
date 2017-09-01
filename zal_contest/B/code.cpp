#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main(int argc, char const *argv[])
{
	ll T;
	cin >> T;
	for(ll p = 0; p < T; p++){
		ll x,y,k,t;
		cin >> x >> y >> k >> t;
		ll cur1 = x;
		ll t1 = t;
		ll k1 = k;
		if (cur1 % y > 0){
			cur1 += y - (cur1 % y);
			k1--;	
		}
		cur1++;
		t1--;

		ll mn = min({k1, t1});
		k1 -= mn;
		t1 -= mn;

		cur1 += y*mn;
		cur1 += t1;
		if (k1 > 0) cur1 += (y - (cur1 % y))%y;

		ll cur2 = x;
		ll t2 = t;
		ll k2 = k;

		if (cur2 % y > 0) {
			ll tm = y - (cur2 % y);
			tm = min({tm, t2});

			cur2 += tm;
			t2 -= tm;
		}
		if (cur2 % y == 0) {
			if (t2 > 0) {
				++cur2;
				--t2;
			}
		} else {
			if (k > 0) {
				cur2 += (cur2 - (cur2 % y))%y;
				--k;
			}
		}
		ll mn2 = min({k2,t2});
		t2 -= mn2;
		k2 -= mn2;
		cur2 += y*mn2;
		cur2 += t2;
		if (k2 > 0) cur2 += (y - (cur2%y))%y;
		cout << max({cur1, cur2}) << endl;
	}
	return 0;
}