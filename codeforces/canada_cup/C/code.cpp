#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	string x;
	cin >> x;
	vector<bool> cnt(26, false);
	char rep;
	for(int i = 0; i < 27; i++){
		if (cnt[x[i]-65]){
			rep = x[i];
			break;
		} 
		else cnt[x[i]-65] = true;
	}
	int s = -1; int e = -1;
	for(int i = 0; i < 27; i++){
		if (x[i] == rep && s == -1){
			s = i;
		}
		else if (x[i] == rep){
			e = i;
		}
	}
	if (e - s == 1){
		cout << "Impossible" << endl;
		return 0;
	}
	vector<vector<char>> a(2, vector<char>(13, '.'));
	int pos_x = 12-((e-s-1)/2);
	a[0][pos_x] = rep;
	int f = s+1;
	int pi = 0;
	int pj = pos_x+1;
	while(f < e){
		a[pi][pj] = x[f];
		if (pj == 12){
			if (pi == 0) pi++;
			else pj--;
		}
		else {
			if (pi == 0) pj++;
			else pj--;
		}
		f++;
	}
	e++;
	int i = 0;
	int j = pos_x-1;
	if (j == -1){
		i = 1;
		j = 0;
	}
	while(e < x.length()){
		a[i][j] = x[e];
		if (j == 0){
			if (i == 0) i++;
			else j++;
		}
		else {
			if (i == 0) j--;
			else j++;
		}
		e++;
	}
	int t = 0;	
	while(t < s){
		a[i][j] = x[t];
		if (j == 0){
			if (i == 0) i++;
			else j++;
		}
		else {
			if (i == 0) j--;
			else j++;
		}
		t++;
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 13; j++){
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}
