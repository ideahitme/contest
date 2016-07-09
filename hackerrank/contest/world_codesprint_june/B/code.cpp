#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	queue<int> a;
	queue<int> b;
	queue<int> c;
	int total_a = 0;
	int total_b = 0;
	int total_c = 0;
	for(int i = 0; i < n1; i++){
		int x;
		cin >> x;
		a.push(x);
		total_a += x;
	}
	for(int i = 0; i < n2; i++){
		int x;
		cin >> x;
		b.push(x);
		total_b += x;
	}
	for(int i = 0; i < n3; i++){
		int x;
		cin >> x;
		c.push(x);
		total_c += x;
	}
	int answer;
	while (total_a != total_b || total_a != total_c){
		bool choose_a = false;
		bool choose_b = false;
		bool choose_c = false;
		if (total_a >= total_b && total_a >= total_c){
			choose_a = true;
		}
		else if (total_b >= total_c && total_b >= total_a){
			choose_b = true;
		}
		else if (total_c >= total_a && total_c >= total_b){
			choose_c = true;
		}
		if (choose_a){
			total_a -= a.front();
			a.pop();
		}
		if (choose_b){
			total_b -= b.front();
			b.pop();
		}
		if (choose_c){
			total_c -= c.front();
			c.pop();
		}
	}
	cout << total_a << endl;
	return 0;
}