#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

struct less_than_key
{
    inline bool operator() (pii struct1, pii struct2)
    {
    	return (struct1.first > struct2.first) || (struct1.first == struct2.first && struct1.second < struct2.second);
    }
};

int main(int argc, char const *argv[])
{
	int K, M, N;
	cin >> K >> M >> N;
	vector<pair<int,int> > occ;
	for(int i = 0; i < M; i++){
		occ.push_back({0, i});
	}
	for(int i = 0; i < N; i++){
		int x;
		cin >> x;
		occ[x].first++;
	}
	sort(occ.begin(), occ.end(), less_than_key());

	for(int i = 0; i < K; i++){
		cout << occ[i].second << endl;
	}	
	return 0;
}
