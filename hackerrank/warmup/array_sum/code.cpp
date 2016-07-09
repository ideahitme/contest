#include <functional>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> v;
	v.push_back(11);
	v.push_back(55);
	v.push_back(22);
	v.push_back(44);
	for(vector<int>::iterator i = v.begin(); i != v.end(); i++){
		cout << *i << endl;
	}
	for(auto i = v.begin(); i != v.end(); i++){
		cout << *i << endl;
	}

	sort(v.begin(), v.end());
	for(auto i = v.begin(); i != v.end(); i++){
		cout << *i << endl;
	}
	v.clear();

	vector<string> strings;

	strings.push_back("Bob");
	strings.push_back("Alice");
	strings.push_back("Aaron");
	strings.push_back("Zach");

	// lexi sort
	sort(strings.begin(), strings.end());

	for(auto i = strings.begin(); i != strings.end(); i++){
		cout << *i << endl;
	}
	// sort backwards
	sort(strings.begin(), strings.end(), greater<string>());
	for(auto i = strings.begin(); i != strings.end(); i++){
		cout << *i << endl;
	}

	// lambda custom
	sort(strings.begin(), strings.end(), [](const string &left, const string &right){
		return left.size() < right.size();
	});
	
	for(auto i = strings.begin(); i != strings.end(); i++){
		cout << *i << endl;
	}
	strings.clear();

	return 0;
}
