#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;


bool good(map<int, int> &ma, map<int, int> &mb){
	for (const auto &entry : ma ) {
		if (mb[entry.first] != ma[entry.first]) {
			return false;
		}
    }
    return true;
}

int main(int argc, char const *argv[])
{
	ifstream infile("anagrams.in");
	ofstream outfile("anagrams.out");
	int n;
	infile >> n;
	vector<int> a(n);
	map<int, int> ma;
	int need_sum = 0;
	for(int i = 0; i < n; i++){
		infile >> a[i];	
		need_sum += a[i];
		if (ma.find(a[i]) == ma.end()){
			ma[a[i]] = 1;
 		} else {
 			ma[a[i]]++;
 		}
	}
	for (const auto &entry : ma ) {
		cout << entry.first << endl;
    }
	int m;
	infile >> m;
	vector<int> b(m);
	map<int, int> mb;
	for(int i = 0; i < m; i++){
		infile >> b[i];
	}
	int cur_sum = 0;
	for(int i = 0; i < n; i++){
		cur_sum += b[i];
		if (mb.find(b[i]) == mb.end()){
			mb[b[i]] = 1;
 		} else {
 			mb[b[i]]++;
 		}		
	}
	if (cur_sum == need_sum && good(ma, mb)){
		outfile << "YES" << endl;
		outfile << 1 << endl;
		return 0;
	}

	for(int i = 1; i <= m-n; i++){
		int next_sum = cur_sum;
		next_sum -= b[i-1];
		next_sum += b[i+n-1];
		mb[b[i-1]]--;
		if (mb.find(b[i+n-1]) == mb.end()){
			mb[b[i+n-1]] = 1;
 		} else {
 			mb[b[i+n-1]]++;
 		}
		if (next_sum == cur_sum){
			continue;
		}
		if (next_sum == need_sum && good(ma, mb)){
			outfile << "YES" << endl;
			outfile << (i+1) << endl;
			return 0;
		}
		cur_sum = next_sum;
	}
	outfile << "NO" << endl;
	return 0;
}
