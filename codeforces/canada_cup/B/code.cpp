#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll res(char x){
	if (x == 'f') return 1;
	if (x == 'e') return 2;
	if (x == 'd') return 3;
	if (x == 'c') return 6;
	if (x == 'b') return 5;
	if (x == 'a') return 4;
	return 0;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	string x;
	cin >> x;
	int len = x.length();
	ll row = 0;
	ll p = 1;
	for(int i = len-2; i >= 0; i--){
		row += p*(static_cast<ll>(x[i])-48);
		p *= 10;
	}
	char seat = x[len-1];
	if (row % 4 == 1 || row % 4 == 2){
		ll travel = row-1;
		ll served = static_cast<ll>(row/4)*12 + ((row%4)-1)*6;
		ll total = travel + served + res(seat);
		cout << total << endl;
	}
	else {
		ll travel = row-3;
		ll rem = (row%4 == 3) ? 0 : 1;
		ll served = static_cast<ll>((row-3)/4)*12 + (rem)*6;
		ll total = travel + served + res(seat);
		cout << total << endl;
	}

	return 0;
}
