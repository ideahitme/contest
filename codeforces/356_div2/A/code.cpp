#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <set>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int main(int argc, char const *argv[])
{
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	vector<int> v = { a, b, c, d, e };	
	sort(v.begin(), v.end());
	int total = 0;
	for(int i = 0; i < 5; i++){
		total += v[i];
	}
	int max = 0;
	if (v[4] == v[3] && v[3] == v[2]){
		max = v[4] + v[3] + v[2];
	}
	else if (v[4] == v[3]){
		if (v[2] == v[1] && v[1] == v[0] && (v[4]+v[3] < v[0] + v[1] + v[2])){
			max = v[0] + v[1] + v[2];
		}
		else {
			max = v[4] + v[3];
		}
	}
	else if (v[3] == v[2]){
		if (v[2] == v[1]){
			max = v[3] + v[2] + v[1];
		}
		else {
			max = v[3] + v[2];
		}
	}
	else if (v[2] == v[1]){
		if (v[1] = v[0]){
			max = v[2] + v[1] + v[0];
		}
		else {
			max = v[2] + v[1];
		}
	} 
	else if (v[1] == v[0]){
		max = v[1] + v[0];
	}
	cout << (total-max) << endl;
	return 0;
}

