#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cmath>

using namespace std;

long long b_search(long long start, long long end, vector<long long> &times, long long products){
	if (start == end){
		return start;
	}
	long long cand = (start+end)/2;
	long long to_be_packed = 0;
	for(int i = 0; i < times.size(); i++){
		to_be_packed += cand/times[i];
	}
	if (to_be_packed < products){
		if (cand == (end-1)){
			return end;
		}
		else return b_search(cand, end, times, products);
	}
	else {
		return b_search(start, cand, times, products);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	long long products;
	int M;
	cin >> products >> M;
	vector<long long> times(M);
	long long max_time = 0;
	for(int i = 0; i < M; i++){
		long long w_time;
		cin >> w_time;
		if (max_time < w_time){
			max_time = w_time;
		}
		times[i] = w_time;
	}		
	long long maximal = max_time*products;
	long long answer = b_search(1, maximal, times, products);
	cout << answer << endl;
	//binary search
	return 0;
}
