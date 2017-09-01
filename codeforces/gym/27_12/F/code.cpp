#include <string>
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
	ifstream infile("minimal.in");
	ofstream outfile("minimal.out");
	string x;
	infile >> x;
	vector<set<int>> hset(26);
	for(int i = 0; i < x.size(); i++){
		int ch = x[i]-97;
		hset[ch].insert(i);
	}

	int t;
	infile >> t;
	for(int i = 0; i < t; i++){
		int l,r;
		infile >> l >> r;
		l--;
		r--;
		int count = 0;
		int cur = l;
		for(int i = 0; i < 26; i++){
			auto it_l = hset[i].lower_bound(cur);
			if (it_l == hset[i].end() || *it_l > r){ //for range l..cur..r, there is no char i in range cur..r 
				it_l = hset[i].lower_bound(l);
				if (it_l == hset[i].end() || *it_l > r) { //no char in range l..r 
					continue;
				} 
				count += r-cur+1;
				cur = l;
				count += (*it_l - l);
				cur = *it_l;
				auto it_r = hset[i].upper_bound(r);
				it_r--;
				if (*it_r == *it_l){
					continue;
				} else {
					count += (*it_r - cur);
					cur = *it_r;
				}
			} else {
				count += (*it_l-cur);
				cur = *it_l;
				auto it_r = hset[i].lower_bound(l);
				if (*it_r == *it_l){
					it_r = hset[i].upper_bound(r);
					it_r--;
					if (*it_r == *it_l) {
						continue;
					}
					count += (*it_r-cur);
					cur = *it_r;
				} else {
					count += r - cur + 1;
					cur = l;
					it_l--;
					count += *it_l - l;
					cur = *it_l;
				}
			}

		}
		outfile << count << endl;
	}
	return 0;
}