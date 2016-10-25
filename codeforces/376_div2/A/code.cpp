#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int PRIME = 1e9+7;
const int MAX = 1e9+10;

int dist(char from, char to){
	return min({abs(to - from), 26-abs(to-from)});
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	string x;
	cin >> x;
	int total = 0;
	char cur = 'a';
	for(int i = 0; i < x.length(); i++){
		char next = x[i];
		total += dist(cur, next);
		cur = next;
	}
	cout << total << endl;
	return 0;
}