#include <vector>
#include <iostream>

using namespace std;

long long main_diagonal(vector<vector<int> > &numbers){
	long long result = 0;
	int size = numbers.size();
	for(int i = 0; i < size; i++){
		result += numbers[i][i];
	}
	return result;
}

long long reverse_diagonal(vector<vector<int> > &numbers){
	long long result = 0;
	int size = numbers.size();
	for(int i = 0; i < size; i++){
		result += numbers[i][size-i-1];
	}
	return result;
}

void print_matrix(vector<vector<int> > &numbers){
	int rows = numbers.size();
	int columns = numbers[0].size();
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			cout << numbers[i][j] << " ";
		}
		cout << endl;
	}
}

void print_vector(vector<int> &numbers){
	for(auto i = numbers.begin(); i != numbers.end(); i++){
		cout << *i << " ";		
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int size;
	cin >> size;
	vector<vector<int> > matrix(size, vector<int>(size));
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cin >> matrix[i][j];
		}
	}
	long long main = main_diagonal(matrix);
	long long reverse = reverse_diagonal(matrix);

	long long answer = abs(main-reverse);
	cout << answer;
	return 0;
}