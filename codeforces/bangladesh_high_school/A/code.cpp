#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  cout << t << endl;
  for (int i = 0; i < t; i++)
  {
    double n, r, p;
    cin >> n >> r >> p;

    long long ll = 0;
    long long rr = 0;

    while (ll < rr)
    {
      long long m = (ll + rr) / 2;
      if (n * pow(1.0 + r / 100.0, double(m)) < p)
      {
        ll = m + 1
      }
      else
      {
        rr = m
      }
    }

    printf("Case %d: %d\n", (i + 1), ll)
  }
}