#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<long long> numbers(n);
	long long total = 0;
	for(int i = 0; i < n; i++){
		cin >> numbers[i];
		total += numbers[i];
	}
	cout << total;
	return 0;
}