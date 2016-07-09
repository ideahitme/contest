#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int num, int limit){
	if (num < 1 || num > limit){
		return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	long long total = 0;
	for(int i = 1; i < n+1; i++){
		int _min = min({a+b+i,a+c+i,b+d+i,c+d+i});
		int _max = max({a+b+i,a+c+i,b+d+i,c+d+i});
		int addition =_min+n-_max;
		if (addition > 0) total += addition;
		//number in the center
		// for(int j = 1; j < n+1; j++){
		// 	//number in the top left corner
		// 	int candidate = a + b + i + j;
		// 	//right top corner
		// 	int right_top = candidate - a - c - i;
		// 	int bottom_left = candidate - b - d - i;
		// 	int bottom_right = candidate - c - d - i;
		// 	if (cmp(right_top, n) && cmp(bottom_left, n) && cmp(bottom_right, n)){
		// 		total ++;
		// 	}
		// }
	}	
	cout << total << endl;
	/* code */
	return 0;
}