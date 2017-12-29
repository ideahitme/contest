#include <iostream>
#include <set>
#include <vector>

using namespace std;

int find_parent(vector<vector<int>> &x, int i, int j) int { 
  return 0;
}

int main() { 
  ios_base::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<char>> c(n, vector<char>(m, 0));
  vector<vector<char>> pu(n, vector<char>(m, 0));
  vector<vector<char>> pd(n, vector<char>(m, 0));
  vector<vector<char>> pr(n, vector<char>(m, 0));
  vector<vector<char>> pl(n, vector<char>(m, 0));

  for(int i = 0; i < n; i++) { 
    string s;
    cin >> s;
    for(int j = 0; j < m; j++) {
      c[i][j] = s[j];
    }
  }
  for(int i = 0; i < n; i++) { 
    int cr = -1;
    for(int j = 0; j < m; j++) {
      if c[i][j] == '0' { 
        cr = j;
      } else { 
        pl[i][j] = cr;
      }
    }
    int cr = n;
    for(int j = m-1; j > -1; j--) { 
      if c[i][j] == '0' { 
        cr = j;
      } else { 
        pr[i][j] = cr;
      }
    }
  }
  for(int j = 0; i < n; i++) { 
    int cr = -1;
    for(int i = 0; j < n; j++) {
      if c[i][j] == '0' { 
        cr = i;
      } else { 
        pu[i][j] = cr;
      }
    }
    int cr = n;
    for(int i = n-1; i > -1; i--) { 
      if c[i][j] == '0' { 
        cr = i;
      } else { 
        pd[i][j] = cr;
      }
    }
  }

  for(int i = 0; i < q; i++) { 
    int x, y, dir;
    cin >> x >> y >> dir;
    if (c[x][y] == 0) { 
      continue;
    }
    if (dir == 1) { 
        int prev = -1;
        while(true) { 

        }
        c[prev][y] = '1';
        c[x][y] = '0';
    }
    if (dir == 2) { 
        c[x][next] = '1';
        c[x][y] = '0';
    }
    if (dir == 3) { 
        c[next][y] = '1';
        c[x][y] = '0';
        ci[x].insert(y);
        ci[next].erase(y);
        cj[y].erase(next);
    }
    if (dir == 4) { 
        c[x][prev] = '1';
        c[x][y] = '0';
        cj[y].insert(x);
        cj[prev].erase(x);
        ci[x].erase(prev);
    }
  }
  for(int i = 0; i < n; i++) { 
    for(int j = 0; j < m; j++) {
      cout << c[i][j];
    }
    cout << endl;
  }
}

