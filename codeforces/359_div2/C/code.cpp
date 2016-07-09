#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

double _log(int n, int base){
	if (n == 0) return 0;
	return log(n)/log(base);
}

bool cmp(int i, int j, bool insert_zero_i, bool insert_zero_j){
	if (insert_zero_i && insert_zero_j) return false;
	set<int> vals;
	if (insert_zero_i || insert_zero_j) vals.insert(0);
	bool ans = true;
	int n = i;
	if (n == 0 && vals.find(0) != vals.end()) return false;
	if (n == 0 && vals.find(0) == vals.end()) vals.insert(0);
	while(n > 0){
		int power = floor(_log(n, 7));
		int digit = floor((double)n/pow(7, power));
		if (vals.find(digit) != vals.end()){
			ans = false;
			break;
		}
		vals.insert(digit);
		int to_substr = digit*pow(7, power);
		n -= to_substr;
	}
	n = j;
	if (n == 0 && vals.find(0) != vals.end()) return false;
	if (n == 0 && vals.find(0) == vals.end()) vals.insert(0);
	while(n > 0){
		int power = floor(_log(n, 7));
		int digit = floor((double)n/pow(7, power));
		if (vals.find(digit) != vals.end()){
			ans = false;
			break;
		}
		vals.insert(digit);
		int to_substr = digit*pow(7, power);
		n -= to_substr;
	}
 	return ans;
}

bool is_unique(int n, bool insert_zero){
	bool ans = true;
	set<int> vals;
	if (insert_zero) vals.insert(0);
	while(n > 0){
		int power = floor(_log(n, 7));
		int digit = floor((double)n/pow(7, power));
		if (vals.find(digit) != vals.end()){
			ans = false;
			break;
		}
		else {
			vals.insert(digit);
		}
		int to_substr = digit*pow(7, power);
		n -= to_substr;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int n_digits = floor(_log(n, 7)) + 1;
	int m_digits = floor(_log(m, 7)) + 1;
	if (n_digits + m_digits > 7){
		cout << 0 << endl;
		return 0;
	}
	ll answer = 0;
	if (n_digits < 4){
		for(int i = 0; i < n; i++){
			if (floor(_log(i, 7)) + 1 >= n_digits - 1 && is_unique(i, floor(_log(i, 7)) + 1 == n_digits - 1)){
				for(int j = 0; j < m; j++){
					if (floor(_log(j, 7)) + 1 >= m_digits - 1 && is_unique(j, floor(_log(j, 7)) + 1 == m_digits - 1)){
						if (cmp(i,j,  floor(_log(i, 7)) + 1 == n_digits - 1, floor(_log(j, 7)) + 1 == m_digits - 1)){
							answer++;
						}
					}
				}
			}
		}
	}
	else if (m_digits < 4){
		for(int i = 0; i < m; i++){
			if (floor(_log(i, 7)) + 1 >= m_digits - 1 && is_unique(i, floor(_log(i, 7)) + 1 == m_digits - 1)){
				for(int j = 0; j < n; j++){
					if (floor(_log(j, 7)) + 1 >= n_digits - 1 && is_unique(j, floor(_log(j, 7)) + 1 == n_digits - 1)){
						if (cmp(i,j,  floor(_log(i, 7)) + 1 == m_digits - 1, floor(_log(j, 7)) + 1 == n_digits - 1)){
							answer++;
						}
					}
				}
			}
		}
	}
	cout << answer << endl;
	return 0;
}
