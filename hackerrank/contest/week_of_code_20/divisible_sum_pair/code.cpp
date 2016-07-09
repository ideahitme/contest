#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	vector<int> numbers;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		numbers.push_back(num);
	}
	int total = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if (i != j && (numbers[i]+numbers[j]) % k == 0){
				total++;
			}
		}
	}
	total = total/2;
	cout << total << endl;
	return 0;
}