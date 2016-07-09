#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cmath>

using namespace std;

double hyp(double a, double b){
	return sqrt(a*a+b*b);
}

bool alternative(double w, double h, double W, double H){
	return (w >= W) && (H > h) && (H >= (2*w*h*W+(w*w-h*h)*sqrt(w*w+h*h-W*W))/(w*w+h*h));
}

int main(int argc, char const *argv[])
{
	double W, H;
	cin >> W >> H;
	int N;	
	cin >> N;
	for(int i = 0; i < N; i++){
		char type;
		cin >> type;
		if (type == 'R'){
			double w,h;
			cin >> w >> h;
			if ((min({w,h}) <= min({W,H}) && max({w,h}) <= max({W,H})) || alternative(max({w,h}), min({w,h}), max({W, H}), min({W,H}))){
				cout << "YES" << endl;
 			}
 			else{
 				cout << "NO" << endl;
 			}
		}
		else{
			double r;
			cin >> r;
			if (r <= ((double)min({W,H})/2)){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
