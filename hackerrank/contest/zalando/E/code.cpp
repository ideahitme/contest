#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cmath>

using namespace std;

vector< vector<int> > getAllSubsets(vector<int> set)
{
    vector< vector<int> > subset;
    vector<int> empty;
    subset.push_back( empty );

    for (int i = 0; i < set.size(); i++)
    {
        vector< vector<int> > subsetTemp = subset;

        for (int j = 0; j < subsetTemp.size(); j++)
            subsetTemp[j].push_back( set[i] );

        for (int j = 0; j < subsetTemp.size(); j++)
            subset.push_back( subsetTemp[j] );
    }
    return subset;
}

bool isPossible(vector<int> selection, const vector<vector<long long> > &warehouses, vector<long long> &query){
	int P = warehouses[0].size();
	vector<long long> total(P);
	for(int i = 0; i < selection.size();i++){
		int warehouse = selection[i];
		for(int i = 0; i < P; i++){
			total[i] += warehouses[warehouse][i];
		}
	}
	bool sat = true;
	for(int i = 0; i < P; i++){
		if (total[i] < query[i]) sat = false;
	}
	return sat;
}

void solution(const vector<vector<long long> > &warehouse, vector<long long> &query){
	vector<int> ws;
	for(int i = 0; i < warehouse.size(); i++){
		ws.push_back(i);
	}
	vector<vector<int>> subsets = getAllSubsets(ws);
	int min = -1;
	for(int i = 0; i < subsets.size(); i++){
		if (isPossible(subsets[i], warehouse, query)){
			if (min == -1 || min > subsets[i].size()){
				min = subsets[i].size();
			}
		}
	}
	cout << min << endl;
}



int main(int argc, char const *argv[])
{
	int W, B, P;
	cin >> W >> B >> P;
	vector<vector<long long> > inventory(W, vector<long long>(P));
	for(int i = 0; i < W; i++){
		for(int j = 0; j < P; j++){
			long long items;
			cin >> items;
			inventory[i][j] = items;
		}
	}
	vector<vector<long long> > queries(B, vector<long long>(P));
	for(int i = 0; i < B; i++){
		for(int j = 0; j < P; j++){
			long long required;
			cin >> required;
			queries[i][j] = required;
		}
	}
	for(int i = 0; i < B; i++){
		solution(inventory, queries[i]);
	}
	return 0;
}
