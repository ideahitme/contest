#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int _ = 0; _ < t; _++)
  {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> c(q + 1, 0);
    for (int i = 0; i < q; i++)
    {
      cin >> c[i];
    }
    vector<vector<int>> qs(q + 1);
    for (int i = 0; i < q; i++)
    {
      int size;
      cin >> size;
      qs[i] = vector<int>(size);
      for (int j = 0; j < size; j++)
      {
        cin >> qs[i][j];
      }
    }
    //calculate next values
    vector<int> count(n + 1, 0);
    vector<int> next(q + 1, 0);
    int card = 0;
    int r = -1;
    for (int l = 0; l < q; l++)
    {
      if (l > 0)
      {
        next[l] = next[l - 1];
      }
      while (card <= k && r < q)
      {
        next[l] = r;
        r++;
        for (int i = 0; i < qs[r].size(); i++)
        {
          count[qs[r][i]]++;
          if (count[qs[r][i]] == 1)
          {
            card++;
          }
        }
      }
      for (int i = 0; i < qs[l].size(); i++)
      {
        count[qs[l][i]]--;
        if (count[qs[l][i]] == 0)
        {
          card--;
        }
      }
    }
    vector<ll> dp(q + 1, 0);
    map<ll, set<int>> m;
    for (int i = q - 1; i > -1; i--)
    {
      dp[i] = ll(c[next[i] + 1]) + dp[next[i] + 1];
      for (int j = next[i + 1]; j > next[i]; j--)
      {
        ll lookUp = ll(c[j]) + dp[j];
        m[lookUp].erase(j);
        if (m[lookUp].size() == 0)
        {
          m.erase(lookUp);
        }
      }
      if (m.size() != 0)
      {
        dp[i] = min(dp[i], m.begin()->first);
      }
      if (m.find(ll(c[i]) + dp[i]) == m.end())
      {
        m[ll(c[i]) + dp[i]] = set<int>{};
      }
      m[ll(c[i]) + dp[i]].insert(i);
    }
    cout << dp[0] << endl;
  }
}