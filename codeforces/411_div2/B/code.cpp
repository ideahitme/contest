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
  int n;
  cin >> n;
  string s(n, 'a');
  for (int i = 2; i < n; i++)
  {
    if (s[i - 2] == 'a')
    {
      s[i] = 'b';
    }
    if (s[i - 2] == 'b')
    {
      s[i] = 'a';
    }
  }
  cout << s << endl;
}