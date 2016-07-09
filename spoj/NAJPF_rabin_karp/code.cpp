#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1e6+1

vector<long long> precompute_poly_hash(string &T, string &P, vector<long long> &powers){
	long long PRIME = 1e9+7;
	int factor = 263;
 	int last_index = T.size()-P.size();
	vector<long long> res(T.size()-P.size()+1);
	long long first_hash = 0;
	for(int i = last_index; i < T.size(); i++){
		first_hash += ((T[i])*(powers[i-last_index] % PRIME)) % PRIME;
	}
	first_hash = first_hash % PRIME;
	res[last_index] = first_hash;
	for(int i = last_index-1; i > -1; i--){
		res[i] = 0;
		res[i] = (T[i] + ((factor%PRIME)*((res[i+1] - (powers[P.size()-1]%PRIME)*(T[i+P.size()]%PRIME)) % PRIME)) % PRIME) % PRIME;
		if (res[i] < 0) res[i] += PRIME;
	}
	return res;
}

long long p_hash(string &P, vector<long long> &powers){
	long long PRIME = 1e9+7;
	int factor = 263;
	long long p_hash = 0;
	for(int i = 0; i < P.size(); i++){
		p_hash += ((P[i]%PRIME)*(powers[i]%PRIME)) % PRIME;
	}	
	p_hash = (p_hash+PRIME) % PRIME;
	return p_hash;
}

bool are_equal(string &T, int start, string &P){
	bool res = true;
	for(int i = start; i < start + P.size(); i++){
		if (T[i] != P[i-start]){
			res = false; break;
		}
	}
	return res;
}

void solution(string &P, string &T, vector<long long> &powers){
	long long PRIME = 1e9+7;
	if (P.size() > T.size()) {
		cout << "Not Found" << endl;
		cout << endl;
		return;
	};
	vector<long long> hashes = precompute_poly_hash(T, P, powers);
	long long hash = p_hash(P, powers);
	vector<int> res;
	for(int i = 0; i < T.size()-P.size()+1; i++){
		if (hashes[i] == hash){
			// if (are_equal(T, i, P)){
				res.push_back(i);
			// }
		}
	}
	if (res.size() > 0){
		cout << res.size() << endl;
		for(int i = 0; i < res.size(); i++){
			cout << (res[i]+1) << " ";
		}
		cout << endl;
	}
	else {
		cout << "Not Found" << endl;
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	long long PRIME = 1e9+7;
	int factor = 263;
	vector<long long> powers(MAX);
	powers[0] = 1;
	for(int i = 1; i < MAX; i++){
		powers[i] = ((powers[i-1] % PRIME)*(factor % PRIME)) % PRIME;
	}
	int test;
	cin >> test;
	for(int i = 0; i < test; i++){
		string P, T;
		cin >> P >> T;
		solution(T, P, powers);		
	}
	return 0;
}