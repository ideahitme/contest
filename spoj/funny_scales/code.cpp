#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void init(ll x, vector<int> &A){
	int curIndex = 0;
	int curPower = 1;
	while(true){
		A[curIndex] = x % 3;
		x = (x-A[curIndex])/3;
		if (x == 0) break;
		curIndex++;
	}
}

int main(int argc, char const *argv[])
{
	vector<int> A(21, 0);
	vector<int> B(21, 0);
	int n;
	ll x;
	cin >> n >> x;
	//check feasibility
	if (x > static_cast<ll>((pow(3, n)-1)/2)) {
		cout << -1 << endl;
		return 0;
	}
	//initialize value of A with digits of x in base-3 representation
	init(x, A);
	for(int i = 0; i < 21; i++){
		if (A[i] == 0){
			//nothing
			continue;
		}
		if (A[i] == 1){
			A[i] = 0;
			B[i] = 1;
			continue;
		}
		if (A[i] == 2){
			A[i] = 1;
			A[i+1]++;
			continue;
		}
		if (A[i] == 3){
			A[i+1]++;
			continue;
		}
	}
	int i;
	i = 1;
	for(auto it: A){
		if (it == 1) cout << i << " ";
		i++;
	}
	cout << endl;
	i = 1;
	for(auto it: B){
		if (it == 1) cout << i << " ";
		i++;
	}
	cout << endl;
	return 0;
}
