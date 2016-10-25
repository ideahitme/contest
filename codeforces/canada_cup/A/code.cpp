#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int len;
	string x;
	cin >> len >> x;
	int i = 0;
	int ans = 0;
	while(x[i] == '<'){
		i++;
		ans++;
	}
	i = len-1;
	while(x[i] == '>'){
		i--;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
