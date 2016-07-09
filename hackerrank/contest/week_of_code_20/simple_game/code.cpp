#include <queue>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

#define MODULO 1000000007

void print_array(vector<int> &arr){
	for(auto i = arr.begin(); i != arr.end(); i++){
		cout << *i << endl;
	}
}
void print_set(set<int> &arr){
	for(auto i = arr.begin(); i != arr.end(); i++){
		cout << *i << endl;
	}
}

void grundy_number(int N, int K){
	cout << "Number of stones: " << N << endl;
	cout << "Value of K: " << K << endl;
	vector<vector<int> > grundy_number(K+1, vector<int>(N+1));
	for(int i = 2; i < K+1; i++){
		for(int j = 1; j < N+1; j++){
			if (i > j){
				grundy_number[i][j] = 0;
			}
			else if (i == j){
				grundy_number[i][j] = 1;
			}
			else if (i == 2){
				int answer = 0;
				set<int> sgrundies;
				for(int k = 1; k < j; k++){
					int x = grundy_number[i][k]^grundy_number[i][j-k];
					sgrundies.insert(x);	
				}
				for(int _ = 0; _ < 1024; _++){
					int cur = *sgrundies.begin();
					if (cur != answer){
						break;
					}
					answer++; 
					sgrundies.erase(sgrundies.begin());
				}
				grundy_number[i][j] = answer;
			}
			else {
				int answer = 0;
				set<int> sgrundies;
				for(int k = 1; k < j; k++){
					int x = grundy_number[i][k]^grundy_number[i-1][j-k];
					sgrundies.insert(x);
				}
				for(int _ = 0; _ < 1024; _++){
					int cur = *sgrundies.begin();
					if (cur != answer){
						break;
					}
					answer++; 
					sgrundies.erase(sgrundies.begin());
				}
				grundy_number[i][j] = answer;
			}
		}
	}
	print_array(grundy_number[3]);
}

int main(int argc, char const *argv[])
{
	int N, M, K;
	cin >> N >> M >> K;
	grundy_number(N, K);
	/* code */
	return 0;
}