#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> arr;
	vector<int> prefix_arr;
	vector<int> suffix_arr;
	map<long long, int> prefix_count;
	long long sum = 0;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		sum += val;
		prefix_arr.push_back(sum);
		if (prefix_count.count(sum)){
			prefix_count[sum]++;
		}
		else{
			prefix_count[sum]=1;
		}
		arr.push_back(val);
	}
	for(int i = arr.size()-1; i > -1; i--){
		
	}
	int max = 0;
	for(auto i = prefix_count.begin(); i != prefix_count.end(); i++){
		if (max < i->second){
			max = i->second;
		}
		// cout << i->first << " " << i->second << endl;
	}
	cout << max << endl;
	return 0;
}
