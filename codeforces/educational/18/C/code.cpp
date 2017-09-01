#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int MAX = 1e9 + 7;

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  vector<int> x(n);
  vector<vector<int>> dp(3, vector<int>(n, MAX));
  int total = 0;
  for (int i = 0; i < n; i++)
  {
    x[i] = s[i] - 48;
  }
  dp[x[n - 1] % 3][n - 1] = 0;

  vector<int> mins(3, MAX);
  mins[x[n - 1] % 3] = 0;

  for (int i = n - 2; i >= 0; i--)
  {
    if (x[i] == 0)
    {
      dp[0][i] = dp[0][i + 1] + 1;
      dp[1][i] = dp[1][i + 1] + 1;
      dp[2][i] = dp[2][i + 1] + 1;
      continue;
    }
    dp[0][i] = min({dp[-x[i] % 3][i + 1] + 1, mins[-x[i] % 3]});
    dp[1][i] = min({dp[(1 - x[i]) % 3][i + 1] + 1, mins[(1 - x[i]) % 3]});
    dp[2][i] = min({dp[(2 - x[i]) % 3][i + 1] + 1, mins[(2 - x[i]) % 3]});
  }
}
