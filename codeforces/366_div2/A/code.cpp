#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n ;
	cin >> n;
	string x;
	for(int i = 0; i < n; i++){
		if (i == n-1){
			if (i % 2 == 0){
				x += "I hate it";
			}
			else {
				x += "I love it";
			}
			break;
		}
		if (i % 2 == 0){
			x += "I hate that ";
		}
		else {
			x += "I love that ";
		}
	}
	cout << x << endl;
	return 0;
}
