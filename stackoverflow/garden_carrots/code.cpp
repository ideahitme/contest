// http://stackoverflow.com/questions/38781428/how-do-you-solve-the-given-scenario-with-given-memory-constraints/38785766#38785766
// 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll calc_in_range(ll pivot, const vector<ll> &p){
	int n = p.size();
	ll total = 0;
	for(int i = 0; i < n; i++){
		if (i == 0) total += static_cast<ll>(upper_bound(p.begin(), p.end(), pivot)-p.begin());
		else total += static_cast<ll>(upper_bound(p.begin() + i, p.end(), pivot + p[i-1]) - p.begin() - i);
	}
	return total;
}


ll calc_sum(ll pivot, const vector<ll> &p, const vector<ll> &pp){
	int n = p.size();
	ll sum = 0;
	int index;
	for(int i = 0; i < n; i++){
		if (i == 0) index = static_cast<ll>(upper_bound(p.begin(), p.end(), pivot)-p.begin());
		else index = static_cast<ll>(upper_bound(p.begin() + i, p.end(), pivot + p[i-1]) - p.begin() - i);
		index--;
		if (index == -1) continue;
		if (i == 0) sum += pp[index];
		else {
			ll shift = p[i-1];
			sum += pp[index+i]-pp[i-1]-shift*(index+1);
		}
	}
	return sum;
}


ll find_x(int a, const vector<ll> &p, const vector<ll> &pp){
	if (a == 0) return 0;
	ll answer = 0;
	ll l = 1;
	ll r = p[p.size()-1];
	int offset;
	while(l < r){
		ll mid = (l+r)/2;
		int cand = calc_in_range(mid, p);
		if (cand <= a){
			l = mid + 1;
			offset = a-cand;
		}
		else {
			r = mid;
			offset = 0;
		}
	}
	ll pivot = l;
	answer += offset * pivot;
	pivot--;
	answer += calc_sum(pivot, p, pp);
	return answer;
}

int main(int argc, char const *argv[])
{
	int n, q;
	cin >> n >> q;
	vector<int> x(n);
	vector<ll> p(n); //prefix array
	vector<ll> pp(n); //prefix sum of prefix array
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cin >> x[i];
		sum += x[i];
		p[i] = sum;
		if (i == 0) pp[i] = p[i];
		else pp[i] = pp[i-1] + p[i];
	}
	for(int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		ll resa = find_x(a-1, p, pp);
		ll resb = find_x(b, p, pp);
		cout << (resb - resa) << endl;
	}
	return 0;
}
