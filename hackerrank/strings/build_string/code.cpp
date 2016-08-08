#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cmath> 

using namespace std;

const int MAX = 1e9;
const int PRIME = 1e9+7;
typedef long long ll;
void powers_of_two(int n, vector<int> &t){
	int x = 1;
	for(int i = 0; i < n; i++){
		t.push_back(x);
		x *= 2;
	}
}

struct _tuple{
	int index;
	int first;
	int second;
	_tuple(int index):index(index) {
		first = -1;
		second = -1;
	}
	~_tuple(){ }
};
/**
 *	longest common prefix of two suffixes starting at indexes i and j
 *	P is defined as in suffix_array
 * 	x initial string
 */

const int d = 22;

vector<int> powers;

int LCP(int i, int j, vector<vector<int>> &P, const string &x){
	int n = x.length();
	if (i == j) return n-i;
	// if (n == 1) return 0;
	int nn = static_cast<int>(floor(log2(n)))+1; //next power of two from length of x
	int total = 0;
	for(int step = nn; step >= 0; step--){
		if (i >= n || j >= n) break;
		if (P[step][i] == P[step][j]){
			total += powers[step];
			i += powers[step];
			j += powers[step];
		}
	}
	return total;	
}

/**
 * suffix array construction in n*log(n)*log(n) time
 * @param SA actual suffix array, s[i] equals to starting index of suffix as ith in order
 * @param P  preliminary result P[i][j] is the rank of suffix at index "j" as compared using first 2^i characters
 * @param x  actual string
 */
void suffix_array(vector<int> &SA, vector<vector<int>> &P, const string &x){
	int n = x.length();
	SA.resize(n, -1);
	int nn = static_cast<int>(floor(log2(n)))+1 ; //next power of two from length of x
	P.resize(nn+1, vector<int>(n, -1));
	if (n == 1) {
		SA[0] = 0;
		P[0][0] = 0;
		return;
	}
	vector<_tuple> L(n, _tuple(0));
	for(int j = 0; j < n; j++){
		P[0][j] = x[j]-'a';
	}
	for(int i = 1; i <= nn; i++){
		for(int j = 0; j < n; j++){
			L[j].index = j;
			L[j].first = P[i-1][j];
			if (j + powers[i-1] < n){
				L[j].second = P[i-1][j+powers[i-1]];
			}
			else L[j].second = -1;
		}
		sort(L.begin(), L.end(), [](const _tuple &a, const _tuple &b){
			return a.first < b.first || (a.first == b.first && a.second < b.second);
		});
		for(int j = 0; j < n; j++){
			if (j == 0){
				P[i][L[j].index] = 0;
			}
			else {
				if (L[j].first == L[j-1].first && L[j].second == L[j-1].second){
					P[i][L[j].index] = P[i][L[j-1].index];
				} else {
					P[i][L[j].index] = j;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		SA[P[nn][i]] = i;
	}
	// uncomment this to see the result
	for(int i = 0; i < n; i++){
		cout << i << " " << (x.substr(SA[i], x.length()-SA[i])) << endl;
	}
}

int main(int argc, char const *argv[])
{
	powers_of_two(d, powers);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n, a, b;
		cin >> n >> a >> b;
		ll total = 0;
		string x;
		cin >> x;
		vector<int> SA;
		vector<vector<int>> P;		
		suffix_array(SA, P, x);
		
	}
	/* code */
	return 0;
}
