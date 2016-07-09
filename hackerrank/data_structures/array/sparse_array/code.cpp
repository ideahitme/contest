#include <iostream>
#include <vector>
#include <string>

using namespace std;

int occur(vector<string> &words, string word){
	int answer = 0;
	for(auto it = words.begin(); it != words.end(); it++){
		if (*it == word){
			answer++;
		}
	}
	return answer;
}	

int main(int argc, char const *argv[])
{
	vector<string> words;
	int size;
	cin >> size;
	for(int i = 0; i < size; i++){
		string word;
		cin >> word;
		words.push_back(word);
	}
	int queries;
	cin >> queries;
	for(int i = 0; i < queries; i++){
		string lookup;
		cin >> lookup;
		cout << occur(words, lookup) << endl;
	}
	return 0;
}