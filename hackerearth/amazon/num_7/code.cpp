#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string x;
	cin >> x;
	reverse(x.begin(), x.end());
	vector<int> d(x.length(), 0);
	int p = 1;
	for(int i = 0; i < x.length(); i++){
		int k = static_cast<int>(x[i])-'0';
		if (i == 0){
			d[i] = k % 7;
		} else {
			d[i] = d[i-1] + k*p;
			d[i] = d[i] % 7;
		}
		p = (p*10) % 7;
	}		
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int l,r;
		cin >> l >> r;
		l = x.length()-l;
		r = x.length()-r;
		if (l > r) swap(l, r);
		int rem;
		if (l == 0){
			rem = d[r] % 7;
		}
		else {
			rem = (d[r]-d[l-1])%7;
		}
		if (rem == 0){
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

