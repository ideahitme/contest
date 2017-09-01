#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    for (int j = 0; j < n; j++)
    {
      cin >> a[j];
      x ^= a[j];
    }
    int answer = 0;
    for (int j = 0; j < n; j++)
    {
      if ((x ^ a[j]) < a[j])
      {
        answer++;
      }
    }
    cout << "Case " << i << ": " << answer << endl;
  }
}