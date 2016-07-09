#include <iostream>
#include <vector>

using namespace std;

int getNext(int index){
	return index + (index & -index);
};

int getParent(int index){
	return index - (index & -index);
}

int update(int val, vector<int> &bit, int index){
	int i = index+1;
	while(i < bit.size()){
		bit[i] += val;
		i = getNext(i);
	}
};

int getSum(vector<int> &bit, int index){
	int i = index + 1;
	int sum = 0;
	while(i > 0){
		sum += bit[i];
		i = getParent(i);
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	vector<int> arr = { 10, 3, 6, 8, -3, 2, 7, 4, 7, 0 };
	//prefix sums are { 10, 13, 19, 27, 24, 26, 33, 37, 44, 44 };
	vector<int> bit(arr.size()+1, 0);
	for(int i = 0; i < arr.size(); i++){
		update(arr[i], bit, i);
	}
	for(int i = 0; i < bit.size(); i++){
		// cout << bit[i] << " " << endl;
	}
	for(int i = 0; i < arr.size(); i++){
		cout << getSum(bit, i) << " " << endl;
	}
	return 0;
}
