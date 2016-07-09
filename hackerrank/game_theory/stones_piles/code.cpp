#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<vector<int> > col;

int grundy_number(set<int> &answers){
	int answer = 0;
	int size = answers.size();
	for(int i = 0; i < size; i++){
		if (*(answers.begin()) != answer){
			break;
		}
		else{
			answers.erase(answers.begin());
			answer++;
		}
	}
	return answer;
}

vector<vector<col> > calc(){
	vector<vector<col> > result(51, vector<col>(50));
	for(int i = 1; i < 51; i++){
		if (i == 1){
			result[1][1] = {{1}};
		}
		else if (i == 2){
			result[2][2] = {{2}};
		}
		else if (i == 3){
			result[3][2] = {{2, 1}};
			result[3][3] = {{3}};
		}
		else {
			result[i][i] = {{i}};
			for(int j = 2; j < i; j++){
				col new_iter;
				for(int k = 1; k < j; k++){
					col iter = result[i-j][k];
					for(int x = 0; x < iter.size(); x++){
						if (iter[x].size() > 0){
							vector<int> to_insert(iter[x]);
							to_insert.push_back(j);
							new_iter.push_back(to_insert);
						}
					}
				}
				result[i][j] = new_iter;
			}
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
vector<int> grundies = {
0,
0,
0,
1,
0,
2,
3,
4,
0,
5,
6,
7,
8,
9,
10,
11,
12,
13,
14,
15,
16,
17,
18,
19,
20,
21,
22,
23,
24,
25,
26,
27,
28,
29,
30,
31,
32,
33,
34,
35,
36,
37,
38,
39,
40,
41,
42,
43,
44,
45,
46};
	int num_cases;
	cin >> num_cases;
	for(int i = 0; i < num_cases; i++){
		int num_stones;
		cin >> num_stones;
		int answer = 0;
		for(int i = 0; i < num_stones; i++){
			int x;
			cin >> x;
			answer = answer ^ grundies[x];
		}
		if (answer == 0){
			cout << "BOB"  << endl;
		}
		else{
			cout << "ALICE"  << endl;
		}
	}
	return 0;
}
