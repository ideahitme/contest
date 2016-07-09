#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int main(int argc, char const *argv[])
{
	cout << 2 << endl;
	string ans;
	cin >> ans;
	vector<int> primes = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int total = 0;
	vector<pii> pairs;
	pairs.push_back({3,3});
	pairs.push_back({5,5});
	pairs.push_back({7,7});
	for(int i = 0; i < primes.size()-1; i++){
		for(int j = i+1; j < primes.size(); j++){
			if (primes[i]*primes[j] <= 100){
				pairs.push_back({primes[i], primes[j]});
			} 
		}
	}
	if (ans == "yes"){
		bool isComposite = false;
		for(int i = 0; i < 15; i++){
			cout << primes[i] << endl;
			string rep;
			cin >> rep;
			if (rep == "yes"){
				isComposite = true;
				break;
			}
		}
		if (isComposite){
			cout << "composite" << endl;
		}
		else {
			cout << "prime" << endl;
		}
	}
	else {
		bool isComposite = false;
		for(int i = 0; i < pairs.size(); i++){
			int prod = pairs[i].first*pairs[i].second;
			cout << prod << endl;
			string res;
			cin >> res;
			if (res == "yes"){
				isComposite = true;
				break;
			}
		}
		if (isComposite){
			cout << "composite" << endl;
		}
		else {
			cout << "prime" << endl;
		}
	}
	return 0;
}
