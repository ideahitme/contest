#include <iostream>
#include <vector>

using namespace std;

int getNext(int index){
	return index + (index & -index);
};

int getParent(int index){
	return index - (index & -index);
}

void update(int val, vector<int> &bit, int index){
	int i = index+1;
	while(i < bit.size()){
		bit[i] += val;
		i = getNext(i);
	}
};

void add_to_range(int val, vector<int> &bit, int l, int r){
	update(val, bit, l);
	update(-val, bit, r+1);
}

int query(int b, vector<int> &bit, vector<int> &arr){
	int sum = 0;
	int i = b+1;
	while(i > 0){
		sum += bit[i];
		i = getParent(i);
	}
	return sum + arr[b];
}

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
	vector<int> arr = { 1, 2, 3, 4, 5, 6 };
	vector<pair<int, int>> pairs = { 
		{3, 4},
		{2, 3},
		// {1, 2}
	};
	for(int i = 0; i < pairs.size(); i++){
		vector<int> bit(arr.size()+1, 0);
		pair<int, int> p = pairs[i];
		int l = p.first;
		int r = p.second;
		add_to_range(l, bit, 0, l-1);
		add_to_range(, bit, r-l+1, r);
		for(int i = 0; i < arr.size(); i++){
			cout << query(i, bit, arr) << " " ;
			// arr[i] = query(i, bit, arr);
		}
		cout << endl;
	}
	return 0;
}
