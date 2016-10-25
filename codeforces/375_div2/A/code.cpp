#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	vector<int> a(3);
	for(int i = 0; i < 3; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int min = 1e8;
	for(int i = a[0]; i <= a[2]; i++){
		int cont = abs(i - a[0]) + abs(i-a[1]) + abs(i-a[2]);
		if (cont < min) {
			min = cont;
		}
	}
	cout << min << endl;
	return 0;
}
