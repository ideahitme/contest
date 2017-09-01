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
	int n, k;
	cin >> n >> k;
	int left = 4*60-k;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if (left >= 5*i){
			left -= 5*i;
			ans++;
		} else {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
