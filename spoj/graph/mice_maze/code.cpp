#include <stdio.h>

int main(int argc, char const *argv[])
{
	const int n = 25;
	const int primes[] = {2,3,5,7};
	for(int i = 0; i < 4; i++){
		int cur = primes[i];
		int total = 0;
		while(cur <= n){
			total += (n/cur);
			cur = cur*primes[i];
		}
		printf("(%d^%d)\n", primes[i], total);
	}
	return 0;
}