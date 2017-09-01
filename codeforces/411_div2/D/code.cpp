#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e9 + 7;

int main()
{
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  vector<int> dp(s.size(), 0);
  ll num_of_b = 0;
  for (int i = s.size() - 1; i > -1; i--)
  {
    if (i == s.size() - 1)
    {
      if (s[i] == 'b')
      {
        num_of_b++;
      }
      continue;
    }
    if (s[i] == 'b')
    {
      dp[i] = dp[i + 1];
      num_of_b++;
    }
    else
    {
      dp[i] = dp[i + 1] + num_of_b;
      num_of_b *= 2;
      num_of_b %= MAX;
      dp[i] %= MAX;
    }
  }
  dp[0] %= MAX;
  cout << dp[0] << endl;
}
// a
// aab -> abba -> bbaba -> bbbbaa
// abab -> 1. bbaab -> bbabba -> bbbbaba -> bbbbbbaaa
//         2. abbba -> bbabba -> bbbbaba -> bbbbbbaaa
// ba
// ab -> bba
// bab = ab
// aab -> a(bbbbbbaaaaaaa) -> num*of*b