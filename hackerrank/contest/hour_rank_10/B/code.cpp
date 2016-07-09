#include <algorithm>
#include <vector>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e9+7;
const ll lMAX = static_cast<ll>(MAX);
const double dMAX = static_cast<double>(MAX);

void print(vector<vector<int>> &arr){
	int r = arr.size();
	int c = arr[0].size();
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if (arr[i][j] == 1)
				cout << 'O';
			else cout << '.';
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int r,c,n;
	cin >> r >> c >> n;
	vector<vector<int>> grid(r, vector<int>(c, 1));
	vector<vector<int>> temp(r, vector<int>(c, 1));
	vector<vector<int>> full(r, vector<int>(c, 1));
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			char x;
			cin >> x;
			if (x == '.'){
				grid[i][j] = 0;
			} else if (x == 'O'){
				grid[i][j] = 1;
			}
			temp[i][j] = grid[i][j];
		}
	}
	if (n == 0 || n == 1) print(grid);
	else if (n % 2 == 0) print(full);
	else {
		n = (n%4)+4;
		for(int s = 0; s < n+1; s++){
			if (s >= 3 && s % 2 == 1){
				for(int i = 0; i < r; i++){
					for(int j = 0; j < c; j++){
						if (i == 0 && j ==0){
							temp[0][0] = !(grid[0][1] || grid[1][0]);
						}
						else if (i == 0 && j < (c-1)){
							temp[0][j] = !(grid[0][j-1] || grid[1][j] || grid[0][j+1]);
						}
						else if (i == 0 && j == (c-1)){
							temp[i][j] = !(grid[0][j-1] || grid[1][j]);
						}
						else if (i == r-1 && j == c-1){
							temp[i][j] = !(grid[i][j-1] || grid[i-1][j]);
						}
						else if (j == 0 && i == r-1){
							temp[i][j] = !(grid[i][j+1] || grid[i-1][j]);
						}
						else if (j == 0 && i < r-1){
							temp[i][j] = !(grid[i][j+1] || grid[i-1][j] || grid[i+1][j]);
						}
						else if (j == c-1 && i > 0){
							temp[i][j] = !(grid[i][j-1] || grid[i-1][j] || grid[i+1][j]);
						}
						else if (i == r-1 && j > 0){
							temp[i][j] = !(grid[i][j+1] || grid[i-1][j] || grid[i][j-1]);
						}
						else {
							temp[i][j] = !(grid[i][j+1] || grid[i-1][j] || grid[i][j-1] || grid[i+1][j]);
						}
						if (grid[i][j] == 1) temp[i][j] = 0;
					}
				}
				for(int i = 0; i < r; i++){
					for(int j = 0; j < c; j++){
						grid[i][j] = temp[i][j];
					}
				}					
			}
		}	
		print(grid);
	}
	return 0;
}
