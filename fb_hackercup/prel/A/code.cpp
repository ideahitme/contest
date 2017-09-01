#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <fstream>
#include <ostream>

using namespace std;
#define PI 3.14159265
typedef pair<double, double> pdd;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	ifstream infile("progress_pie.txt");
	ofstream outfile("output.out");
	int t;
	infile >> t;
	for(int i = 1; i <= t; i++){
		int p;
		int x,y;
		infile >> p >> x >> y;
		double dist = sqrt((x-50)*(x-50)+(y-50)*(y-50));
		if (dist - 50.0 > 1e-9) {
			outfile << "Case #" << i << ": " << "white" << endl;
			continue;
		}
		pdd vec1 = {0.0, 50.0};
		pdd vec2 = {double(x)-50.0, double(y)-50.0};
		double dist1 = 50.0;
		double dist2 = sqrt(vec2.first*vec2.first+vec2.second*vec2.second);
		double scalar = 50*(vec2.second);
		double cos_v = scalar/(dist1*dist2);
		double angle = acos(cos_v)* 180.0 / PI;
		double elapsed = 3.6*double(p);
		if (angle - elapsed > 1e-9){
			outfile << "Case #" << i << ": " << "white" << endl;
		} else {
			outfile << "Case #" << i << ": " << "black" << endl;
		}
	}
	return 0;
}