#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, num_queries;
	int last_answer = 0;
	cin >> n >> num_queries;
	vector<vector<long long> > list(n);
	for(int i = 0; i < num_queries; i++){
		long long type, x, y;
		cin >> type >> x >> y;
		if (type == 1){
			int to_insert = (x ^ last_answer) % n;
			list[to_insert].push_back(y);
		}
		if (type == 2){
			int to_insert = (x ^ last_answer) % n;
			int seq_length = list[to_insert].size();
			int lookup = y % seq_length;
			last_answer = list[to_insert][lookup];
			cout << last_answer << endl;
		}
	}
	return 0;
}
