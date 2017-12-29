#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

int main() { 
  string s;
  cin >> s;
  int n = s.length();

  vector<int> c(26, 0);
  for(int i = 0; i < s.length(); i++) { 
    c[s[i]-'a']++;
  }

  vector<int> pos(n, -1);
  vector<int> shft(26, 0);
  for(int i = 0; i < n; i++) { 
    char ch = s[i];
    int shift = shft[ch-'a'];
    int total = shift;
    for(int j = 0; j < ch-'a'; j++) { 
      total += c[j];
    }
    pos[total] = i;
    shft[ch-'a']++;
  }

  sort(s.begin(), s.end());

  while(true) { 
    int ts = -1;
    for(int j = 0; j < n; j++) { 
      if (j != pos[j]) { 
        ts = j;
      }
    }
    if (ts == -1) { 
      break;
    }

    if (s[ts] < s[pos[ts]]) { 
      cout << (pos[ts]+1) << " " << (ts+1) << endl;
    } else if (s[ts] > s[pos[ts]]) { 
      cout << (ts+1) << " " << (pos[ts]+1) << endl;
    }
    char ctmp = s[ts];
    s[ts] = s[pos[ts]];
    s[pos[ts]] = ctmp;

    pos[pos[ts]] = pos[ts];
    pos[ts] = ts;
  }
}