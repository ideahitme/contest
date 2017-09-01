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
  if (n % 2 == 1)
  {
    cout << n / 2 << endl;
  }
  else
  {
    cout << n / 2 - 1 << endl;
  }
}