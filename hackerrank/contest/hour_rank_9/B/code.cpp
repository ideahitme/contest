#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

void solution(vector<int> &h){
	vector<long long> prefix_sum;
	long long sum_so_far = 0;
	for(auto i = h.begin(); i != h.end(); i++){
		sum_so_far += *i;
		prefix_sum.push_back(sum_so_far);
	}
	int curS = 1;
	int curExperience = 0;
	long long curMax = prefix_sum[h.size()-1];
	for(int defeated = 1; defeated < h.size(); defeated++){
		int newS = 1 + defeated;
		long long candidate = newS * (prefix_sum[h.size()-1]-prefix_sum[defeated-1]);
		if (candidate > curMax){
			curMax = candidate;
		}
	}
	cout << curMax << endl;	
}

int main(int argc, char const *argv[])
{
	int num_cases;
	cin >> num_cases;
	for(int i = 0; i < num_cases; i++){
		vector<int> health;
		int size;
		cin >> size;
		for(int j = 0; j < size; j++){
			int x;
			cin >> x;
			health.push_back(x);
		}
		sort(health.begin(), health.end());
		solution(health);
	}
	/* code */
	return 0;
}
