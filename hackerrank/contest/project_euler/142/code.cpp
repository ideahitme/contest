#include <cmath>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isPerfectSquare(long long n){
	long long cand = (long long)(sqrt(n));
	return cand * cand == n;
}

void add_triplet(long long a, long long b, long long c, int &M, int N){
    for(int i = 1; i < N+1; i++){
        long long a_i = a * i * i;
        long long b_i = b * i * i;
        long long c_i = c * i * i;
        if (c_i >= 1e12 || M == 0){
        	break;
        }
        M--;
        cout << c_i << " " << b_i << " " << a_i << endl;
    }
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int M = N;
    long long a;
    long long b;
    long long c;
	a = 16860888/9; b = 20593512/9; c = 21591513/9;
	add_triplet(a, b, c, M, N);
	a = 22011022; b = 23147378; c = 25433522;
	add_triplet(a, b, c, M, N);
	a = 26633678; b = 29316722; c = 40606322;
	add_triplet(a, b, c, M, N);
	a = 28189728; b = 32650272; c = 45495328;
	add_triplet(a, b, c, M, N);
	c = 9004913; b = 8845712; a = 8626688;
	add_triplet(a, b, c, M, N);
    a = 150568;
 	b = 420968;
 	c = 434657;
 	add_triplet(a, b, c, M, N);
    a = 418304;
    b = 488000;
    c = 733025;
 	add_triplet(a, b, c, M, N);
    a = 856350;
    b = 949986;
    c = 993250;  
 	add_triplet(a, b, c, M, N);

	return 0;
}
