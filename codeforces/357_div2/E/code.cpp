#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

double dist(int x, int y){
	return sqrt(x*x+y*y);
}

typedef pair<double, double> pdd;

pair<pair<double, double>, pair<double, double>> inters(int x, int y, int r, int R){
	double d = dist(x, y);
	double l = (R*R-r*r+d*d)/(2*d);
	double h = sqrt(R*R-l*l);
	double x1 = (l/d)*x + (h/d)*y;
	double x2 = (l/d)*x - (h/d)*y;
	double y1 = (l/d)*y - (h/d)*x;
	double y2 = (l/d)*y + (h/d)*x;

	pair<pair<double, double>, pair<double, double>> res = {{x1, y1}, {x2, y2}};
	return res;
} 

int main(int argc, char const *argv[])
{
	int x, y, v, T;
	cin >> x >> y >> v >> T;
	long long R = v*T;
	double PI = atan(1)*4;
	double P = 2.0 * PI * R;
	double total = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int xi, yi, ri;
		cin >> xi >> yi >> ri;
		xi = xi-x;
		yi = yi-y;
		if (dist(xi, yi) <= ri) {
			double res = 1.0;
			cout << res << endl;
			return 0;
		}
		if (ri + R > dist(xi, yi)){
			pair<pdd,pdd> inter = inters(xi, yi, ri, R);
			pdd f = inter.first;
			pdd s = inter.second;
			double dist = sqrt((f.first-s.first)*(f.first-s.first) + (f.second-s.second)*(f.second-s.second));
			double angle = acos(1 - (dist*dist)/(2*R*R));
			total += R*angle;
		}
	}
	double res = (total/P);
	cout << res << endl;
	return 0;
}
