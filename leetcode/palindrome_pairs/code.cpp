#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cmath> 
#include <assert.h>
#include <set>

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

const int d = 24;

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
			else L[j].second = -1000;
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
	// for(int i = 0; i < n; i++){
	// 	cout << i << " " << (x.substr(SA[i], x.length()-SA[i]))<< " " << SA[i] << endl;
	// }
}
/**
 * basically binary search in x, its SA and pattern to be matched
 * @param x  [description]
 * @param SA [description]
 * @param p  [description]
 */

int find_range_l(const string &x, const vector<int> &SA, int l, int r, int shift, char chr){
	if (l >= r) return (SA[l]+shift < x.length() && x[SA[l]+shift] == chr) ? l: -1;
	int mid = (l+r)/2;
	int imid = SA[mid] + shift;
	if (imid < x.length()){
		if (x[imid] >= chr){
			return find_range_l(x,SA,l,mid,shift,chr);
		}
		else {
			return find_range_l(x,SA,mid+1,r,shift,chr);
		}
	}
	else {
		find_range_l(x,SA,mid+1,r,shift,chr);
	}
}
int find_range_r(const string &x, const vector<int> &SA, int l, int r, int shift, char chr){
	if (l >= r) return (SA[l]+shift < x.length() && x[SA[l]+shift] == chr) ? l: -1;
	int mid = ceil(static_cast<double>((l+r))/2.0);
	int imid = SA[mid] + shift;
	if (imid < x.length()){
		if (x[imid] <= chr){
			return find_range_r(x,SA,mid,r,shift,chr);
		}
		else {
			return find_range_r(x,SA,l,mid-1,shift,chr);
		}
	}
	else {
		find_range_r(x,SA,mid,r,shift,chr);
	}
}

string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "ATCG";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str( length,0 );
    generate_n( str.begin(), length, randchar );
    return str;
}

void matching(const string &x, const vector<int> &SA, const string &p, vector<int> &res){
	int l = 0;
	int r = x.length()-1;
	bool match = true;
	for(int i = 0; i < p.length(); i++){ //i-th char of p is the one to be matched within range l..r in SA
		char chr = p[i];
		int nl = find_range_l(x,SA,l,r,i,chr);
		int nr = find_range_r(x,SA,l,r,i,chr);
		l = nl;
		r = nr;
		if (l == -1 || r == -1 || l > r) {
			match = false;
			break;
		}
	}
	if (match){
		for(int i = l; i <= r; i++){
			res.push_back(SA[i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	powers_of_two(d, powers);
	vector<string> words;
	string rev;
	int n; cin >> n;
	vector<vector<int>> res(n);
	for(int i = 0; i < n; i++){
		string x; 
		cin >> x;
		cout << x << endl;
		words.push_back(x);
		string y = x;
		reverse(y.begin(), y.end());
		rev += '$' + y;
	}
	vector<int> SA;
	vector<vector<int>> P;
	suffix_array(SA, P, rev);
	cout << rev << endl;
	for(int i = 0; i < n; i++){
		string y = '$' + words[i];
		matching(rev, SA, y, res[i]);
	}
	
	return 0;
}
