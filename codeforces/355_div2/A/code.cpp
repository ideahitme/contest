#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, h;
	cin >> n >> h;
	int width = 0;
	for(int i = 0; i < n; i++){
		width++;
		int _h;
		cin >> _h;
		if (_h > h){
			width++;
		}
	}
	cout << width << endl;
	return 0;
}
