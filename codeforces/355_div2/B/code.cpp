#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, h, k;
	cin >> n >> h >> k;
	vector<int> potatoes;
	int len = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		len += x;
		potatoes.push_back(x);
	}
	if (k == 1){
		cout << len << endl;
	}
	else{
	int total = 0;
	int next_potato = 0;
	long long sum_so_far = 0;
	while(true){
		sum_so_far += potatoes[next_potato];
		if (sum_so_far > h){
			sum_so_far -= potatoes[next_potato];
			total += sum_so_far/k;
			sum_so_far = sum_so_far % k;
			if (sum_so_far + potatoes[next_potato] > h){
				total += 1;
				sum_so_far = 0;
			}
		}
		else{
			next_potato++;
		}
		if (next_potato == n) break;
	}
	if (sum_so_far > 0){
		total += ceil((double)sum_so_far/k);
	}	
	cout << total << endl;		
	}

	/* code */
	return 0;
}
