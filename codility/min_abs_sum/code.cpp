#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int solution(vector<int> &A) {
	if (A.size() == 0) return 0;
    int n = A.size();
    vector<int> count(101, 0);
    ll total = 0;
    int max_el = -1;
    for(int i = 0; i < n; i++){
    	if (A[i] < 0) A[i] = -A[i];
    	total += A[i];
    	max_el = max({max_el, A[i]});
    	count[A[i]]++;
    }
    vector<int> dp(total+1, -1);
    dp[0] = 0;
    //if dp[i] >= 0 then some sub_sum equals i
    for(int i = 0; i < max_el + 1; i++){
    	int total_occ = count[i];
    	for(int j = 0; j < total+1; j++){
    		if (dp[j] < 0 && j >= i){
    			if (dp[j-i] > 0) dp[j] = dp[j-i] - 1;
    		}
    		else if (dp[j] >= 0){
    			dp[j] = total_occ;
    		}
    	}
    }
    int min = 1e9;
    for(int i = 0; i < total+1; i++){
    	if (dp[i] >= 0 && min > abs(total-2*i)){
    		min = abs(total-2*i);
    	}
    }
    return min;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	cout << solution(A) << endl;
	return 0;
}
