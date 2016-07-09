#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cmath>

using namespace std;

#define MAX 99999999;

struct dims{
	int w;
	int h;
	int l;
};

dims calc_dims(int a, int b, int c, int N){
	int osx, osy, osz;
	dims d = {0, 0, 0};
	long long val = MAX;
	for(int depth = 1; depth < N+1; depth++){
		osz = depth*c;
		int in_area = ceil((double)N/depth);
		for(int height = 1; height < in_area+1; height++){
			int width = ceil((double)in_area/height);
			osx = min({a,b})*min({width, height});
			osy = max({a,b})*max({width, height});
			// cout << osx << " " << osy << " " << osz << " " << endl;
			if (val > 2*(osx*osy+osz*osy+osx*osz)){
				val = 2*(osx*osy+osz*osy+osx*osz);
				d = {osx, osy, osz};
			}
			// cout << val << endl;
		}
	};
	for(int depth = 1; depth < N+1; depth++){
		osz = depth*a;
		int in_area = ceil((double)N/depth);
		for(int height = 1; height < in_area+1; height++){
			int width = ceil((double)in_area/height);
			osx = min({c,b})*min({width, height});
			osy = max({c,b})*max({width, height});
			// cout << osx << " " << osy << " " << osz << " " << endl;
			if (val > 2*(osx*osy+osz*osy+osx*osz)){
				val = 2*(osx*osy+osz*osy+osx*osz);
				d = {osx, osy, osz};
			}
			// cout << val << endl;
		}
	};
	for(int depth = 1; depth < N+1; depth++){
		osz = depth*b;
		int in_area = ceil((double)N/depth);
		for(int height = 1; height < in_area+1; height++){
			int width = ceil((double)in_area/height);
			osx = min({c,a})*min({width, height});
			osy = max({c,a})*max({width, height});
			// cout << osx << " " << osy << " " << osz << " " << endl;
			if (val > 2*(osx*osy+osz*osy+osx*osz)){
				val = 2*(osx*osy+osz*osy+osx*osz);
				d = {osx, osy, osz};
			}
			// cout << val << endl;
		}
	};
	for(int depth = 1; depth < N+1; depth++){
		osz = depth*c;
		int in_area = ceil((double)N/depth);
		for(int height = 1; height < in_area+1; height++){
			int width = ceil((double)in_area/height);
			osx = min({a,b})*max({width, height});
			osy = max({a,b})*min({width, height});
			// cout << osx << " " << osy << " " << osz << " " << endl;
			if (val > 2*(osx*osy+osz*osy+osx*osz)){
				val = 2*(osx*osy+osz*osy+osx*osz);
				d = {osx, osy, osz};
			}
			// cout << val << endl;
		}
	};
	for(int depth = 1; depth < N+1; depth++){
		osz = depth*a;
		int in_area = ceil((double)N/depth);
		for(int height = 1; height < in_area+1; height++){
			int width = ceil((double)in_area/height);
			osx = min({c,b})*max({width, height});
			osy = max({c,b})*min({width, height});
			// cout << osx << " " << osy << " " << osz << " " << endl;
			if (val > 2*(osx*osy+osz*osy+osx*osz)){
				val = 2*(osx*osy+osz*osy+osx*osz);
				d = {osx, osy, osz};
			}
			// cout << val << endl;
		}
	};
	for(int depth = 1; depth < N+1; depth++){
		osz = depth*b;
		int in_area = ceil((double)N/depth);
		for(int height = 1; height < in_area+1; height++){
			int width = ceil((double)in_area/height);
			osx = min({c,a})*max({width, height});
			osy = max({c,a})*min({width, height});
			// cout << osx << " " << osy << " " << osz << " " << endl;
			if (val > 2*(osx*osy+osz*osy+osx*osz)){
				val = 2*(osx*osy+osz*osy+osx*osz);
				d = {osx, osy, osz};
			}
			// cout << val << endl;
		}
	};
	// try other comb
 	return d;
}

int find_val(dims d){
	int osx = d.w;
	int osy = d.h;
	int osz = d.l;
	int min = 2*(osx*osy+osz*osy+osx*osz);
	return min;
}

int solution(int w, int h, int l, int N){
	cout << N << endl;
	int answer = MAX;
	if (N == 1){
		return find_val(calc_dims(w,h,l,N));
	}
	for(int k = 2; k < N+1; k++){
		if (N % k == 0){
			dims d = calc_dims(w,h,l,k);
			int cand;
			if (k == N){
				cand = find_val(d);
			}
			else{
				cand = solution(d.w, d.h, d.l, N/k);
			}
			if (cand < answer){
				answer = cand;
			}
		}
	}
	return answer;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int w, l, h;
	cin >> w >> l >> h;

	int answer = solution(w,h,l,N);
	cout << answer << endl;
	return 0;
}
