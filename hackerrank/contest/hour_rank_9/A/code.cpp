#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	vector<int> distr;
	cin >> N;
	for(int i = 0; i < N; i++){
		int x;
		cin >> x;
		distr.push_back(x);
	}	
	int total = 0;
	for(int i = 0; i < N-1; i++){
		if (distr[i] % 2 == 0){
			continue;
		}
		else{
			distr[i]++;
			distr[i+1]++;
			total += 2;
		}
	}
	if (distr[N-1] % 2 == 1){
		cout << "NO" << endl;
	}
	else{
		cout << total << endl;
	}
	/* code */
	return 0;
}
