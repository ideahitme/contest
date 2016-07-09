#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <set>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

long long to_cube(int i){
	return i*i*i;
}

void answer(long long m){
	int size = 1e5+1;
	long long sofar = 0;
	int total_cubes = 0;
	vector<int> cubes(size, 0);
	vector<pii> path;
	for(int i = 0; i < size; i++){
		if (i*i*i > m) break; 
		path.push_back({i, 0});
	}
	for(int i = 1; i < size; i++){
		long long next_cube = (i+1)*(i+1)*(i+1);
		long long cur_cube = i*i*i;
		long long diff = next_cube-1-sofar;
		long long to_add = diff/cur_cube;
		sofar += to_add*cur_cube;
		total_cubes += to_add;
		path[i] = {i, to_add};
		if (sofar >= m){
			long long pen = sofar-m;
			int to_remove = ceil((double)pen/cur_cube);
			int new_val = path[i].second-to_remove;
			path[i] = {i, new_val};
			total_cubes -= to_remove;
			sofar -= to_remove*(cur_cube);
			break;
		}
	}
	int last_chosen;
	for(int i = 1; i < path.size(); i++){
		if (path[i].second > 0){
			last_chosen = i;
		}
	}
	long long max = sofar;
	long long max_limit = path.size();
	while(true){
		for(int i = last_chosen+1; i < max_limit; i++){
			long long candidate = sofar-to_cube(last_chosen) + to_cube(i);
			if (candidate <=m && candidate < to_cube(i+1)){
				max = candidate;
			}
		}
		max_limit = last_chosen+1;
		int j = last_chosen-1;
		while(path[j].second == 0 && j > 0){
			j--;
		}
		last_chosen = j;
		if (j == 0) break;
	}
	for(int i = 1; i < path.size(); i++){
		long long candidate = sofar-to_cube(last_chosen) + to_cube(i);
		if (candidate <=m && candidate < to_cube(i+1)){
			max = candidate;
		}
		cout << path[i].first << " " << path[i].second << endl;
	}	
	cout << total_cubes << " " << max << endl;
}

int main(int argc, char const *argv[])
{
	long long m;
	cin >> m;
	answer(m);
	return 0;
}
