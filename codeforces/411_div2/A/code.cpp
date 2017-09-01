#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
  ios::sync_with_stdio(false);
  int l, r;
  cin >> l >> r;
  if (r - l >= 5)
  {
    cout << 2 << endl;
    return 0;
  }
  if (r == l)
  {
    cout << r << endl;
    return 0;
  }
  int two = 0;
  int three = 0;
  for (int i = l; i <= r; i++)
  {
    if (i % 2 == 0)
    {
      two++;
    }
    if (i % 3 == 0)
    {
      three++;
    }
  }
  if (two > three)
  {
    cout << 2 << endl;
  }
  else
  {
    cout << 3 << endl;
  }
}