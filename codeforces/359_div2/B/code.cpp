#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

void solution(vector<int> &a, vector<int> &sorted, int l, int r){
	if (l > r) return;
	int i = l;
	while(a[i] != sorted[i] && i < r){
		swap(a[i], a[i+1]);
		i++;
		cout << (i+1) << " " << (i+2) << endl;
	}
	solution(a, sorted, l, i-1);
	solution(a, sorted, i+1, r);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> sorted(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sorted[i] = a[i];
	}
	sort(sorted.begin(), sorted.end());
	for(int i = 0; i < n; i++){
		int index = n-i-1;
		for(int j = 0; j < n-i; j++){
			if (a[j] == sorted[index]){
				for(int k = j; k < n-i-1; k++){
					swap(a[k], a[k+1]);
					if (k+3 >= n-i-1 || a[k+2] < a[k+3])
						cout << (k+1) << " " << (k+2) << endl;
					else{
						swap(a[k+2], a[k+3]);
						cout << (k+1) << " " << (k+4) << endl;
					}
				}
			}
		}
	}
	return 0;
}
