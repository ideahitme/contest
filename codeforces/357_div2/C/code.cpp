#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1e9+1

struct cmp_rev
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<string, int>> res;
	priority_queue<int, vector<int>, cmp_rev> q;

	for(int i = 0; i < n; i++){
		string x;
		cin >> x;
		if (x == "insert"){
			int val;
			cin >> val;
			q.push(val);
			res.push_back({"insert", val});
		}
		if (x == "getMin"){
			int val;
			cin >> val;
			if (q.empty()){
				q.push(val);
				res.push_back({"insert", val});
				res.push_back({"getMin", val});
			}
			else if (q.top() > val){
				q.push(val);
				res.push_back({"insert", val});
				res.push_back({"getMin", val});
			}
			else if (q.top() < val){
				while(!q.empty() && q.top() < val){
					q.pop();
					res.push_back({"removeMin", MAX});
				}
				if (q.empty()){
					q.push(val);
					res.push_back({"insert", val});
					res.push_back({"getMin", val});
				}
				else if (q.top() > val){
					q.push(val);
					res.push_back({"insert", val});
					res.push_back({"getMin", val});
				}
			}
			else {
				res.push_back({"getMin", val});
			}
		}
		if (x == "removeMin"){
			if (!q.empty()){
				q.pop();
				res.push_back({"removeMin", MAX});
			}
			else {
				res.push_back({"insert", -1000});
				res.push_back({"removeMin", MAX});
			}
		}
	}
	cout << res.size() << endl;
	for(auto i = res.begin(); i != res.end(); i++){
		if (i->second != MAX) cout << i->first << " " << i->second << endl;
		else cout << i->first << endl;
	}
	return 0;
}
