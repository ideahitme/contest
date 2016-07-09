#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b){
		cout << "YES" << endl;
	}
	else if (c == 0){
		cout << "NO" << endl;
	}
	else if ((b - a) % c == 0 && c > 0 && b > a){
		cout << "YES" << endl;
	}
	else if ((b - a) % c == 0 && c < 0 && b < a){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}
