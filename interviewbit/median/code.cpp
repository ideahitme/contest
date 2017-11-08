#include <vector>
#include <iostream>

using namespace std;

int val(const vector<int> &a, const vector<int> &b, int x, int y)
{
  if (y < 0)
  {
    return 1;
  }
  if (b.size() < y)
  {
    return -1;
  }
  if (b.size() == y)
  {
    if (b[y - 1] <= a[x])
    {
      return 0;
    }
    else
    {
      return -1;
    }
  }
  if (a[x] > b[y])
  {
    return 1;
  }
  if ((y - 1 >= 0) && (a[x] < b[y - 1]))
  {
    return -1;
  }
  return 0;
}

int cand(const vector<int> &a, const vector<int> &b, int i)
{
  int l = 0;
  int r = a.size() - 1;

  while (l < r)
  {
    int med = (l + r) / 2;

    int t = val(a, b, med, i - med);
    if (t == 0)
    {
      l = med;
      break;
    }
    if (t == -1)
    {
      l = med + 1;
    }
    if (t == 1)
    {
      r = med;
    }
  }

  return l;
}

double median(const vector<int> &a, const vector<int> &b, int i)
{
  int l = cand(a, b, i);
  if (val(a, b, l, i - l) == 0)
  {
    return double(a[l]);
  }

  l = cand(b, a, i);
  if (val(b, a, l, i - l) == 0)
  {
    return double(b[l]);
  }

  return -1.0;
}

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
  int total = A.size() + B.size();
  int lpos = (total - 1) >> 1;
  int rpos = total - lpos - 1;

  if (A.size() == 0)
  {
    return (double(B[lpos]) + double(B[rpos])) / 2;
  }
  if (B.size() == 0)
  {
    return (double(A[lpos]) + double(A[rpos])) / 2;
  }

  double i = median(A, B, lpos);
  double j = median(A, B, rpos);
  return (i + j) / 2;
}

int main()
{
  int n;
  cin >> n;

  vector<int> a = vector<int>(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int m;
  cin >> m;

  vector<int> b = vector<int>(m, 0);
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  cout << findMedianSortedArrays(a, b) << endl;
}
