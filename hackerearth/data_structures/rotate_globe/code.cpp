#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int tests;
	cin >> tests;
	for(int t = 0; t < tests; t++){
		long long N;
		int M;
		cin >> N >> M;
		vector<pair<int, int>> ranges;
		for(int i = 0; i < M; i++){
			int l,r;
			cin >> l >> r;
			ranges.push_back({l, r});
		}
		sort(ranges.begin(), ranges.end());
		string answer = "YES";
		for(int i = 1; i < M; i++){
			if (ranges[i].first == ranges[i-1].first){
				answer = "NO";
				break;
			}
		}
		cout << answer << endl;
	}
	return 0;
}

