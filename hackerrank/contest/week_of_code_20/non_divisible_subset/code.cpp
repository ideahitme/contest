#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<vector<long long> > remainder_set(100);
	vector<long long> numbers;
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		long long num;
		cin >> num;
		numbers.push_back(num);
		int remainder = (num % k);
		remainder_set[remainder].push_back(num);
	}
	int half = ceil((float)k/2);
	int answer = 0;
	for(int i = 1; i < half; i++){
		int compare = max(remainder_set[i].size(), remainder_set[k-i].size());
		answer += compare;
	}
	if (remainder_set[0].size() > 0){
		answer ++;
	}
	if (k % 2 == 0 && remainder_set[half].size() > 0){
		answer ++;
	}
	cout << answer;
	return 0;
}
