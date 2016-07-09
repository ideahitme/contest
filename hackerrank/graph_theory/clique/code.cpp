#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

/** upper bound on the number of edges a graph with N vertices can have if does not have clique of size M */
int turan(int n, int m){
	double coff = (1 - 1/(static_cast<double>(m-1))) * static_cast<double>(n) * static_cast<double>(n)/2;		
	return floor(coff);
}

int bin_search(int l, int r, int n, int target){
	if (r > l) return l;
	int m = (l+r)/2;
	if (turan(n, m) >= target) return bin_search(l, m, n, target);
	else {
		return bin_search(m+1, r, n, target);
	}

}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n, e;
		cin >> n >> e;
		int min = 3;
		int max = n;
		cout << bin_search(min, max, n, e);
	}
	return 0;
}