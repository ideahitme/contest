#include <set>
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		ll n,x,y,z;
		cin >> n >> x >> y >> z;
		set<int> f = {2,3,5,7};
		bool omg = true;
		ll holy_grail = -1;
		for(int j = 0; j < n; j++){
			ll val; cin >> val;
			if (f.find(x) != f.end()) while(val % x == 0){
				val /= x;
			}
			if (f.find(y) != f.end()) while(val % y == 0){
				val /= y;
			}
			if (f.find(z) != f.end()) while(val % z == 0){
				val /= z;
			}
			if (holy_grail == -1) holy_grail = val;
			else{
				if (holy_grail != val){
					omg = false;
					break;
				}
			}
		}
		if (omg){
			cout << "She can" << endl;
		}
		else {
			cout << "She can't" << endl;
		}
	}

	return 0;
}
