#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ifstream infile("road.in");
	ofstream ostream("road.out");
	int n;
	infile >> n;
	vector<int> c(100001);
	int cur = 0;
	stack<int> s;
	for(int i = 0; i < n; i++){
		int t;
		infile >> t;
		if (t > 0){
			s.push(t);
			c[t] = 1;
			cur = t;
			ostream << cur << endl;
		}
		if (t < 0){
			if (cur + t == 0){
				if (s.size() == 0) {
					cur = 0;
				}
				while(s.size() > 0) {
					s.pop();
					if (s.size() == 0) {
						cur = 0;
						break;
					}
					int f = s.top();
					if (c[f] != -1) {
						cur = f;
						break;
					}
				}
				ostream << cur << endl;
			} else {
				c[-t] = -1;
				ostream << cur << endl;
			}
		}	
		if (t == 0) {
			if (s.size() == 0) {
				cur = 0;
			}

			while(s.size() > 0) {
				s.pop();
				if (s.size() == 0) {
					cur = 0;
					break;
				}
				int f = s.top();
				if (c[f] != -1) {
					cur = f;
					break;
				}
			}
			ostream << cur << endl;			
		}
	}

	return 0;
}