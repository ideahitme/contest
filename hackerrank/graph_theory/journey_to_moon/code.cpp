#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <limits>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

class DisjointSet{
public:
	DisjointSet();
	DisjointSet(int n);
	~DisjointSet();
	int find(int i){
		if (p[i] == i) return i;
		return p[i] = find(p[i]);
	}
	void unite(int i, int j){
		i = find(i);
		j = find(j);
		if (i == j) return;
		if (rand() % 2 == 0){
			swap(i, j);
		}
		p[i] = j;
		size[j] += size[i];
		size[i] = 0;
	}
	ll calc(){
		ll total = 0;
		int n = size.size();
		for(int i = 0; i < size.size(); i++){
			total += static_cast<ll>(size[i]*(n-size[i]));
		}
		total /= 2;
		return total;
	}
private:
	vector<int> p;
	vector<int> size;
};

DisjointSet::DisjointSet(int n){
	size.resize(n, 1);
	for(int i = 0; i < n; i++){
		p.push_back(i);
	}
};
DisjointSet::~DisjointSet(){};

int main(int argc, char const *argv[])
{
	int n, l;
	cin >> n >> l;
	DisjointSet d(n);
	for(int i = 0; i < l; i++){
		int a,b;
		cin >> a >> b;
		d.unite(a, b);
	}
	cout << d.calc() << endl;
	/* code */
	return 0;
}