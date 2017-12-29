#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(false);
	return 0;
}

int Solution(vector<vector<int>> &A, int target) {
    int n = A.size();
    int m = A[0].size();
    int l = 0;
    int r = n*m-1;
    while(l < r) {
        int mm = l + (r-l)/2;
        int row = mm/m;
        int col = mm % m;
        if (A[row][col] >= target) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return A[l/n][l%n] == target;
}
