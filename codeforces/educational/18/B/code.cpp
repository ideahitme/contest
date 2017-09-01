#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  for (int i = 0; i < k; i++)
  {
    cin >> a[i];
  }

  vector<bool> x(n, false);
  int cur = 0;
  int m = n;
  for (int i = 0; i < k; i++)
  {
    int shift = a[i] % m;
    while (shift > 0)
    {
      cur = ++cur % n;
      if (!x[cur])
      {
        shift--;
      }
    }
    x[cur] = true;
    cout << (cur + 1) << " ";
    while (x[cur])
    {
      cur = ++cur % n;
    }
    m--;
  }
  cout << endl;
}