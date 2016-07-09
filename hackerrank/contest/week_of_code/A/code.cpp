#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int x1, v1, x2, v2;
	cin >> x1 >> v1 >> x2 >> v2;
	if (x1 == x2) {
		cout << "YES" << endl;
		return 0;
	}
	if (x1 < x2){
		if (v1 <= v2){
			cout << "NO" << endl;
			return 0;
		}
		while(x1 < x2){
			x1 += v1;
			x2 += v2;
		}
		if (x1 == x2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	else if (x2 < x1){
		if (v2 <= v1){
			cout << "NO" << endl;
			return 0;
		}
		while(x2 < x1){
			x1 += v1;
			x2 += v2;
		}
		if (x1 == x2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
