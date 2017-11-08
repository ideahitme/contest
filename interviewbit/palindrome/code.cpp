#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

int isPalindrome(string &x);

bool isAlphaNum(char x)
{
  return ('0' <= x && x <= '9') ||
         ('a' <= x && x <= 'z') ||
         ('A' <= x && x <= 'Z');
}

int main()
{
  string x = "A man, a plan, a canal: Panama";

  cout << isPalindrome(x) << endl;
}

int isPalindrome(string &A)
{
  int j = A.length() - 1;
  for (int i = 0; i < A.length(); i++)
  {
    if (!isAlphaNum(A[i]))
    {
      continue;
    }
    while (j >= 0 && !isAlphaNum(A[j]))
    {
      j--;
    }
    if (j == -1)
    {
      return 0;
    }
    if (tolower(A[i]) != tolower(A[j]))
    {
      return 0;
    }
    j--;
  }
  return 1;
}
