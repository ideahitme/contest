#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <map>
#include <fstream>
#include <ostream>
#include <sstream>

using namespace std;

typedef long long ll;

vector<vector<double>> det(int d){
	int t = 20;
	int m = t*d;
	vector<vector<double>> dp(t+1, vector<double>(m+1, 0));
	for(int i = 1; i <= d; i++){
		dp[1][i] = 1.0/d;
	}
	int cur_max = d;
	for(int i = 2; i <= t; i++){
		for(int j = 1; j <= (cur_max+d); j++){
			for(int k = 1; k <= d; k++){
				if (j >= k) dp[i][j] += dp[i-1][j-k]/d;
			}
		}
		cur_max += d;
	}
	return dp;
}

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	ifstream infile("input");
	ofstream outfile("output.out");
	outfile.precision(15);
	outfile << fixed;
	map<int, vector<vector<double>>> res;
	vector<int> y = {4,6,8,10,12,20};
	for(int i = 0; i < y.size(); i++){
		res[y[i]] = det(y[i]);
	}
	int t;
	infile >> t;
	for(int i = 0; i < t; i++){
		int h, s;
		infile >> h >> s;
		double ans = 0;
		for(int i = 0; i < s; i++){
			double prob = 0;
			string x;
			infile >> x;
			vector<string> splited;
			split(x, 'd', splited);
			int t = stoi(splited[0]);
			int d = -1;
			int z = 0;
			bool is_plus = true;
			vector<string> plussub;
			split(splited[1], '+', plussub);
			if (plussub.size() > 1) {
				d = stoi(plussub[0]);
				z = stoi(plussub[1]);
			} else {
				vector<string> minussub;
				split(splited[1], '-', minussub);
				d = stoi(minussub[0]);
				if (minussub.size() > 1){
					is_plus = false;
					z = stoi(minussub[1]);
				}
			}
			int goal;
			if (is_plus){ 
				goal = h-z;
			} else {
				goal = h+z;
			}
			if (goal > 0 && goal <= d*t) {
				vector<double> to_iter = res[d][t];
				for(int i = 1; i < goal; i++){
					prob += to_iter[i];
				}
				prob = 1-prob;
			} else if (goal <= 0) {
				prob = 1;
			}
			if (prob > ans) {
				ans = prob;
			}
		}
		outfile << "Case #" << (i+1) << ": " << ans << endl;
	}
	return 0;
}