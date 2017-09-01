#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <set>
#include <queue>
#include <cmath>
#include <assert.h>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1e9;
const ll lMAX = 1e18;
const int PRIME = 1e9+7;


int main(int argc, char const *argv[])
{
	ifstream infile("competition.in");
	ofstream outfile("competition.out");
	int n, k;
	infile >> n >> k;
	vector<vector<int>> x(n, vector<int>(k, 0));

	int min_index, max_index;
	max_index = 0;
	min_index = 3;
	vector<int> prev{5,5,5,0};
	for(int i = 0; i < n; i++){
		vector<int> next{0,0,0,0};
		if (i == 0) {
			next = prev;
		} else {
			for(int l = 0; l < 4; l++){
				next[l] = prev[l]+1;
			}
			next[max_index] = 0;
			min_index = max_index;
			int _max = -1e8;
			int new_max_index;
			for(int i = 0; i < 4; i++){
				if (_max < next[i]){
					_max = next[i];
					new_max_index = i;
				}
			}
			max_index = new_max_index;
		}

		int j = 0;
		while(j < k){
			x[i][j] = next[j%4];
			j++;
		}
		prev = next;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			outfile << x[i][j] << " ";
		}
		outfile << endl;
	}
	return 0;
}