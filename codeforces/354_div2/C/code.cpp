#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

void print_arr(vector<int> &arr){
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	vector<int> word;
	string in;
	cin >> in;
	int total_a = 0;
	int total_b = 0;
	for(char &c: in){
		if (c == 'a'){
			total_a += 1;
			word.push_back(0);
		}
		if (c == 'b'){
			total_b += 1;
			word.push_back(1);
		}
	}
	if (n == 1){
		cout << 1 << endl;
	}
	else {
		int answer = 1;
		int a = total_a;
		int b = total_b;
		vector<int> a_from_end;
		vector<int> b_from_end;
		for(int i = 0; i < n; i++){
			a_from_end.push_back(a);
			b_from_end.push_back(b);
			if (word[i] == 0){
				a--;
			}
			if (word[i] == 1){
				b--;
			}
		}
		vector<int> _a(total_a+1);
		vector<int> _b(total_b+1);
		int i_a = total_a;
		int i_b = total_b;
		for(int i = 0; i < n; i++){
			_a[i_a] = i;
			_b[i_b] = i;
			if (word[i] == 0){
				i_a--;
			}
			if (word[i] == 1){
				i_b--;
			}
		}
		if (_a[0] == 0){
			_a[0] = n;
		}
		for(int i = 0; i < n; i++){
			int num_a_till_end = a_from_end[i];
			int num_b_till_end = b_from_end[i];
			if (num_a_till_end <= k || num_b_till_end <= k){
				if (n-i > answer){
					answer = n-i;
					continue;
				}
			}
			else{
				int diff_b = num_b_till_end-k;
				int index_b = _b[diff_b];
				int diff_a = num_a_till_end-k;
				int index_a = _a[diff_a];
				int index = max(index_a, index_b);
				// cout << i << " " << diff_a << " " << diff_b << " " << index_a << " " << index_b << endl;
				if (index-i > answer){
					answer = index-i;
					continue;
				}
			}
		}
		cout << answer << endl;
	}
	return 0;
}
