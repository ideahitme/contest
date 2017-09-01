#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	if (n == 1) {
		cout << "-1" << endl;
		return 0;
	}
	if (n % 2 == 1){
		long long m = static_cast<long long>(n+1);
		long long x,y,z;
		x = m;
		y = m*(m-1);
		z = m-1;
		cout << x << " " << y << " " << z << endl;
	} else {
		cout << (3*n)/2 << " " << 3*n << " " << n << endl;
	}
	return 0;
}

// (1 + 1) = (1/n + (n-1)/n + 1)

// x = n*2
// y = (n-1)*n
// z = n
