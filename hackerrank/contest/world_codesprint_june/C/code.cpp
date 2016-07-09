#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <sstream>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

const char* hex_char_to_bin(char c)
{
	if (c == '\0') return "0000";
    // TODO handle default / error
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
    return "d";
}

unordered_map<string, char> m;


void convert(char A, char B, char C, string &nA, string &nB, int &K) {
	string xA = hex_char_to_bin(A);
	string xB = hex_char_to_bin(B);
	string xC = hex_char_to_bin(C);
	for(int i = 0; i < 4; i++){
		if (xC[i] == '1'){
			if (xA[i] == '0' && xB[i] == '0'){
				xB[i] = '1';
				K--;
			}
		}
		else {
			if (xA[i] == '1'){
				xA[i] = '0';
				K--;
			}
			if (xB[i] == '1'){
				xB[i] = '0';
				K--;
			}
		}
	}
	nA += m[xA];
	nB += m[xB];
}

void minimizeA(char A, char B, char C, string &nA, string &nB, int &buffer) {
	string xA = hex_char_to_bin(A);
	string xB = hex_char_to_bin(B);
	string xC = hex_char_to_bin(C);
	for(int i = 0; i < 4; i++){
		if (xC[i] == '1'){
			if (xA[i] == '1' && xB[i] == '1' && buffer >= 1){
				xA[i] = '0';
				buffer--;
			}
			if (xA[i] == '1' && xB[i] == '0' && buffer >= 2){
				xB[i] = '1';
				xA[i]  ='0';
				buffer -= 2;
			}
		}
	}
	if (nA.length() == 0 && m[xA] == '0') {

	} else nA += m[xA];
	if (nB.length() == 0 && m[xB] == '0') {
	} else nB += m[xB];
}

// void minimizeB(char A, char B, char C, string &nA, string &nB, int &buffer) {
// 	string xA = hex_char_to_bin(A);
// 	string xB = hex_char_to_bin(B);
// 	string xC = hex_char_to_bin(C);
// 	for(int i = 0; i < 4; i++){
// 		if (xC[i] == '1'){
// 			if (xA[i] == '1' && xB[i] == '1' && buffer >= 1){
// 				xB[i] = '0';
// 				buffer -= 2;
// 			}
// 		}
// 	}

// 	nA += m[xA];
// 	if (nA.length() == 2) nA.erase(nA.begin(), std::find_if(nA.begin(), nA.end(), std::bind1st(std::not_equal_to<char>(), '0')));
// 	nB += m[xB];
// 	if (nB.length() == 2) nB.erase(nB.begin(), std::find_if(nB.begin(), nB.end(), std::bind1st(std::not_equal_to<char>(), '0')));
// 	// cout << xA << " " << xB << " " << xC << " " << endl;
// }

int main(int argc, char const *argv[])
{       
	m["0000"] = '0';
    m["0001"] = '1';
    m["0010"] = '2';
    m["0011"] = '3';
    m["0100"] = '4';
    m["0101"] = '5';
    m["0110"] = '6';
    m["0111"] = '7';
    m["1000"] = '8';
    m["1001"] = '9';
    m["1010"] = 'A';
    m["1011"] = 'B';
    m["1100"] = 'C';
    m["1101"] = 'D';
    m["1110"] = 'E';
    m["1111"] = 'F';
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int K;
		cin >> K;
		string A, B, C;
		string nA = "";
		string nB = "";
		cin >> A >> B >> C;
		int len = max({C.length(), A.length(), B.length()});
		if (len != A.length()){
			string addA(len-A.length(), '0');
			A = addA + A;
		}
		if (len != B.length()){
			string addB(len-B.length(), '0');
			B = addB + B;
		}
		if (len != C.length()){
			string addC(len-C.length(), '0');
			C = addC + C;
		}
		for(int i = 0; i < len; i++){
			convert(A[i],B[i],C[i], nA, nB, K);
			if (K < 0){
				break;
			}
		}
		if (K >= 0){
			string nnA = "";
			string nnB = "";
			len = max({C.length(), nA.length(), nB.length()});
			if (len != nA.length()) {
				string naddA(len-nA.length(), '0');
				nA = naddA + A;
			}
			if (len != nB.length()){
				string naddB(len-nB.length(), '0');
				nB = naddB + B;
			}
			if (len != C.length()){
				string naddC(len-C.length(), '0');
				C = naddC + C;
			}
			for(int i = 0; i < len; i++){
				minimizeA(nA[i],nB[i],C[i], nnA, nnB, K);
			}
			if (nnA.length() == 0) nnA = "0";
			if (nnB.length() == 0) nnB = "0";
			cout << nnA << endl;
			cout << nnB << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}