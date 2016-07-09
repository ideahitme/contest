#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cmath>

using namespace std;

struct order{
	int A;
	int B;
	int C;
};

vector<string> split(const string &text, char sep) {
  vector<string> tokens;
  size_t start = 0, end = 0;
  while ((end = text.find(sep, start)) != string::npos) {
    tokens.push_back(text.substr(start, end - start));
    start = end + 1;
  }
  tokens.push_back(text.substr(start));
  return tokens;
}

int getMaxType(int Na,int Nb,int Nc){
	if (max({Na, Nb, Nc}) == Na){
		return 0;
	}
	if (max({Na, Nb, Nc}) == Nb){
		return 1;
	}
	if (max({Na, Nb, Nc}) == Nc){
		return 2;
	}
	return 0;
}

int sizeOfOrder(order &o){
	return o.A+o.B+o.C;
}

int getSize(order &o, int type){
	if (type == 0){
		return o.A;
	}
	if (type == 1){
		return o.B;
	}
	if (type == 2){
		return o.C;
	}
	return 0;
}

int pick_to_satisfy(vector<order> &orders, vector<bool> &satisfied, int type, int Na, int Nb, int Nc){
	int pick = -1;
	int size = 4;
	for(int i = 0; i < orders.size(); i++){
		if (!satisfied[i] && (getSize(orders[i], type) > 0)){
			if ((pick == -1 || size > sizeOfOrder(orders[i])) && Na >= orders[i].A && Nb >= orders[i].B && Nc >= orders[i].C){
				pick = i;
				size = sizeOfOrder(orders[i]);
			}
		}
	}
	return pick;
}

void solution(vector<order> &orders,int Na,int Nb,int Nc){
	int total = 0;
	vector<bool> satisfied(orders.size(), false);
	for(int i = 0; i < orders.size(); i++){
		if (Na + Nb + Nc == 0){
			break;
		}
		int max_type = getMaxType(Na, Nb, Nc);
		int pick = pick_to_satisfy(orders, satisfied, max_type, Na, Nb, Nc);
		if (pick == -1){
			if (max_type == 0){
				Na = 0;
			}
			if (max_type == 1){
				Nb = 0;
			}
			if (max_type == 2){
				Nc = 0;
			}
			// break;
		}
		else{
			// cout << pick << endl;
			satisfied[pick] = true;
			Na -= orders[pick].A;
			Nb -= orders[pick].B;
			Nc -= orders[pick].C;
			total ++;
		}
	}
	cout << total << endl;
}

int main(int argc, char const *argv[])
{
	int Na, Nb, Nc;
	cin >> Na >> Nb >> Nc;
	int total_orders;
	cin >> total_orders;
	vector<order> orders(total_orders);
	for(int i = 0; i < total_orders; i++){
		string order;
		cin >> order;
		vector<string> splited = split(order, ',');
		int a = 0;
		int b = 0;
		int c = 0;
		for(int i = 0; i < splited.size(); i++){
			if (splited[i] == "A"){
				a = 1;
			}
			if (splited[i] == "B"){
				b = 1;
			}
			if (splited[i] == "C"){
				c = 1;
			}
		}
		orders[i] = {a,b,c};
	}
	solution(orders, Na, Nb, Nc);
	return 0;
}
