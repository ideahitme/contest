#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

typedef double coord_t;
typedef double coord2_t;

struct Point {
	coord_t x, y;

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);

	sort(P.begin(), P.end());

	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k-1);
	return H;
}

double area(vector<Point> &convex, int a, int b, int c){
	double x_a = convex[a].x; 
	double y_a = convex[a].y;
	double x_b = convex[b].x; 
	double y_b = convex[b].y;
	double x_c = convex[c].x; 
	double y_c = convex[c].y;
	double area = abs(x_a*y_b + x_b*y_c + x_c*y_a - x_a*y_c - x_c*y_b - x_b*y_a);
	area *= 0.5;
	return area;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long S;
	cin >> S;
	vector<Point> points;
	for(int i = 0; i < n; i++){
		double x, y;
		cin >> x >> y;
		Point p;
		p.x = x;
		p.y = y;
		points.push_back(p);
	}
	vector<Point> convex = convex_hull(points);
	int A = 0;
	int B = 1;
	int C = 2;
	int bA = A;
	int bB = B;
	int bC = C;
	while(true){
		while(true){
			while (area(convex, A,B,C) <= area(convex, A, B, ((C+1)%n))){
				C = (C+1) %n;
				if (C == 0) break;
			}
			if (area(convex, A,B,C) <= area(convex, A, (B+1)%n, C)){
				B = (B+1) % n;
				if (B == 0) break;
				continue;
			}
			else break;
		}
		if (area(convex, A,B,C) > area(convex, bA, bB, bC)){
			bA = A;
			bB = B;
			bC = C;
		}
		A = (A+1)%n;
		if (A == B){
			B = (B+1)%n;
		}
		if (B == C){
			C = (C+1)%n;
		}
		if (A == 0) break;
	}
	double x_a = convex[bA].x; 
	double y_a = convex[bA].y;
	double x_b = convex[bB].x; 
	double y_b = convex[bB].y;
	double x_c = convex[bC].x; 
	double y_c = convex[bC].y;
	int res_x_a = (int)(x_b+x_c-x_a);
	int res_y_a = (int)(y_b+y_c-y_a);
	int res_x_b = (int)(x_a+x_c-x_b);
	int res_y_b = (int)(y_a+y_c-y_b);
	int res_x_c = (int)(x_a+x_b-x_c);
	int res_y_c = (int)(y_a+y_b-y_c);
	cout << res_x_a << " " << res_y_a << endl;
	cout << res_x_b << " " << res_y_b << endl;
	cout << res_x_c << " " << res_y_c << endl;
	return 0;
}
