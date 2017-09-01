#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e9+10;
const int PRIME = 1e9 + 7;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	bool cor = true;
	int cur = 0;
	for(int i = 0; i < t; i++){
		int dist;
		string x;
		cin >> dist >> x;
		if (x == "North"){
			if (cur < dist){
				cor = false;
				break;
			}
			cur -= dist;
		}
		if (x == "South"){
			if (cur > 20000-dist){
				cor = false;
				break;
			}
			cur += dist;
		}
	}
	if (cur != 0){
		cor = false;
	}
	if (cor) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
