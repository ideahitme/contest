#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cmath>

using namespace std;

typedef pair<long long, long long> pll;

int main(int argc, char const *argv[])
{
	int N;
	vector<pll> orders(60, {-1, -1});
	cin >> N;
	for(int i = 0; i < N; i++){
		int type;
		cin >> type;
		if (type == 1){
			long long price, curtime;
			cin >> price >> curtime;
			int index = 0;
			while(index < 60){
				if (orders[index].first == -1){
					orders[index] = {price, curtime};
					break;
				}
				else {
					if (curtime-orders[index].second >= 60){
						orders[index] = {price, curtime};
						break;
					}
					else if (orders[index].first <= price){
						orders[index] = {price, curtime};
						break;
					}
				}
				index++;
			}
			if (index == 60){
				orders[59] = {price, curtime};
			}
		}
		else{
			long long curtime;
			long long lmax = -1;
			cin >> curtime;
			for(int i = 0; i < 60; i++){
				if (curtime - orders[i].second <= 59 && lmax <= orders[i].first){
					lmax = orders[i].first;
				}
			}
			cout << lmax << endl;
		}
	}
	return 0;
}
