#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> f(1e5 + 1, 0);

    ll answer = 0;
    bool at_least_two = false;

    for (ll j = 0; j < n; j++)
    {
      cin >> a[j];
      f[a[j]]++;
      if (f[a[j]] > 1)
      {
        at_least_two = true;
      }
    }

    for (int j = 0; j <= 1e5; j++)
    {
      answer += (n - f[j]) * f[j];
    }

    answer /= 2;
    if (at_least_two)
    {
      answer++;
    }
    cout << answer << endl;
  }
}