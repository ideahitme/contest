#include <vector>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int a = -1;
	int b = -1;
	for(int i = 0;i < N; i++){
		int n;
		cin >> n;
		if (a != -1 && b == -1 && n == N){
			b = i;
		}
		if (a != -1 && b == -1 && n == 1){
			b = i;
		}
		if (a == -1 && n == 1){
			a = i;
		}
		if (a == -1 && n == N){
			a = i;
		}
	}
	if (a > (N-1-b)){
		cout << b << endl;
	}
	else{
		cout << (N-a-1) << endl;
	}
	return 0;

}
