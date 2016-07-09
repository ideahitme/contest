#include <vector>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,k;
	cin >> n >> k;
	int total = n*(n+1);
	if (k > total){
		cout << total << endl;
	}
	else{
		int lvl = 1;
		while(lvl*(lvl+1) < k){
			lvl++;
		}
		lvl--;
		cout << (lvl*(lvl+1)) << endl;
	}
	return 0;
}

