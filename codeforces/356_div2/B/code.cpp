#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <set>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int main(int argc, char const *argv[])
{
	int n, a;
	cin >> n >> a;
	a = a-1;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		arr[i] = x;
	}
	int total = 0;
	for(int i = 0; i < n; i++){
		if (a-i >= 0 && a+i <= n-1){
			if (i == 0){
				total += arr[a];
			}
			else {
				total += 2*((arr[a-i] + arr[a+i])/2);
			}
		}
		else if (a-i >= 0){
			total += arr[a-i];
		}
		else if (a+i <= n-1){
			total += arr[a+i];
		}
		else break;
	}
	cout << total << endl;
	return 0;
}
