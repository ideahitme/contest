#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

void iterate(int t, int cur, int diff, vector<int> &shifts, vector<int> &s, vector<double> &vals, int p, double r, vector<vector<double>> &res){
	if (cur == shifts.size()){
		double sum = 0.0;
		vector<double> local;
		bool all_zero = true;
		for(int i = 0; i < vals.size(); i++){
			local.push_back((double)(shifts[i] + s[i]));
			if (shifts[i] != 0) all_zero = false;
			sum += vals[i];
		}
		local.push_back(sum);
		if (all_zero){
			cout << fixed << setprecision(3) << sum << endl;
		}
		if (res.size() < 3){
			res.push_back(local);
		}
		else {
			sort(res.begin(), res.end(),
			[](const vector<double>& a, const vector<double>& b) {
				return a[a.size()-1] > b[b.size()-1];
			});
			if (local[local.size()-1] > res[res.size()-1][local.size()-1]){
				res.pop_back();
				res.push_back(local);
			}
		}
		return;
	}
	if ((shifts.size()-cur)*t < abs(diff)) return;
	if (cur < shifts.size()-1){
		for(int i = -t; i <= t; i++){
			shifts[cur] = i;
			if (s[cur] + shifts[cur] > 0 && s[cur] + shifts[cur] < 100){
				if (cur == 0){
					vals[0] = ((double) p) * ((double)s[cur] + (double)shifts[cur]);
					vals[0] /= 100.0;
					vals[0] *= (1.0 + r);
				}
				else {
					double new_val = (double)p*(double)((double)s[cur] + (double)shifts[cur])*(1.0+r)/100.0;
					for(int i = 0; i < cur; i++){
						new_val *= (1.0-(double(s[i]+shifts[i])/100));
						new_val *= (1.0+r);
					}
					vals[cur] = new_val;
				}
				iterate(t, cur+1, diff+i, shifts, s, vals, p, r, res);
			}
			else if (s[cur] + shifts[cur] == 0){
				vals[cur] = 0.0;
				iterate(t, cur+1, diff+i, shifts, s, vals, p, r, res);
			}
		}	
	} 
	else{
		shifts[cur] = -diff;
		double new_val = (double)p*(double)((double)s[cur] + (double)shifts[cur])*(1.0+r)/100.0;
		for(int i = 0; i < cur; i++){
			new_val *= (1.0-(double(s[i]+shifts[i])/100));
			new_val *= (1.0+r);
		}
		vals[cur] = new_val;		
		iterate(t, cur+1, 0, shifts, s, vals, p, r, res);
	}
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int p, n, t;
	double r;
	cin >> p >> r >> n >> t;
	r /= 100.0;
	vector<int> shifts(n, 0);
	vector<double> vals(n, 0);
	vector<int> s;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s.push_back(x);
	}
	vector<vector<double>> res;
	iterate(t, 0, 0, shifts, s, vals, p, r, res);
	sort(res.begin(), res.end(),
	[](const vector<double>& a, const vector<double>& b) {
		return a[a.size()-1] > b[b.size()-1];
	});
	for(int i = 0; i < res.size(); i++){
		vector<double> l = res[i];
		cout << res[i][res[i].size()-1] << " - ";
		for(int j = 0; j < res[i].size()-1; j++){
			cout << (int)res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
	