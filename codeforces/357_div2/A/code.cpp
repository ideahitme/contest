#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string res = "NO";
	for(int i = 0; i < n; i++){
		string h;
		int b,a;
		cin >> h >> b >> a; 
		if (b >= 2400 && b < a){
			res = "YES";
			break;
		}
	}	
	cout << res << endl;
	return 0;
}
