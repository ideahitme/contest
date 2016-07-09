#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int solution(int num_students, int K){
	return 0;
}

int main(int argc, char const *argv[])
{
	int num_cases;
	cin >> num_cases;
	for(int i = 0; i < num_cases; i++){
		int num_students, K;
		int result = 0;
		cin >> num_students >> K;
		for(int j = 0; j < num_students; j++){
			int arrival;
			cin >> arrival;
			if (arrival <= 0) {
				result ++;
			}
		}
		if (result >= K) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	int num_students;
	return 0;
}