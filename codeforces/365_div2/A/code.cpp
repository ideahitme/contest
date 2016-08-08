#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1e9 + 7;
const int PRIME = 1e9 + 7;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int m = 0;
	int c = 0;
	for(int i = 0; i < n; i++){
		int x,y;
		cin >> x >> y;
		if (x > y) m++;
		else if (x < y) c++;
	}
	if (m > c){
		cout << "Mishka" << endl;
	}
	else if (m < c){
		cout << "Chris" << endl;
	}
	else {
		cout << "Friendship is magic!^^" << endl;
	}
	return 0;
}
