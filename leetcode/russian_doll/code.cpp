#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	vector<pii> a;
	int prs;
	cin >> prs;
	for(int i = 0; i < prs; i++){
		int x,y;
		cin >> x >> y;
		a.push_back(make_pair(x,y));
	}
	sort(a.begin(), a.end());
	vector<vector<pii>> res(a.size());
	res[0].push_back(a[0]);
	for(int i = 1; i < a.size(); i++){
		pii cur_pair = a[i];
		int to_copy_from = i;
		size_t max_len = 0;
		for(int j = 0; j < i; j++){
			if (a[j].first < cur_pair.first && a[j].second < cur_pair.second){
				if (max_len < (res[j].size()+1)){
					max_len = res[j].size();
					to_copy_from = j;
				}
			}
		}
		vector<pii> cp(res[to_copy_from]);
		res[i] = cp;
		res[i].push_back(cur_pair);
	}
	int _max = -1;
	for(int i = 0; i < a.size(); i++){
		_max = max({static_cast<int>(res[i].size()), _max});
	}
	cout << _max << endl;
	return 0;
}
