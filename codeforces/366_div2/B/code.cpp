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
	int n;
	cin >> n;
	int _xor = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		_xor = _xor ^ (1-a % 2);
		if (_xor == 0){
			cout << "2" << endl;			
		}
		else cout << "1" << endl;
	}
	return 0;
}
