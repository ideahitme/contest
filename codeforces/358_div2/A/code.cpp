#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <cmath> 

using namespace std;

long long num_remain(int n, int rem){
	if (rem == 0){
		return floor((double)n/5);
	}
	int x = (n % 5 >= rem) ? 1:0;
	return floor((double)(n)/5.0) + x;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	long long res = 0;
	for(int i = 0; i <= 4; i++){
		res += num_remain(n, i) * num_remain(m, 5-i);
 	}
	cout << res << endl;
	return 0;
}
